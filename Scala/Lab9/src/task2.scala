// Our task 2 for today is to implement mapReduce model with Futures.
//
// MapReduce model is way to handle distributed calculations on many many
// machines (in our case we will use Futures for that and cores of our single machine).
// The idea is simple:
//
//  You split input data into chunks.
//  You calculate result for each of the chunks (map).
//  You combine results for each of the chunks into one single final result (reduce).
//
//  Today we are going to write mapReduce model for finding biggest and lowest
//  number in the random number list. According to the explanation of our
//  idea, here's today's program plan:
//
//  - Split list of random numbers into 10 chunks.
//  - Create sequence of features for each chunk, where each future will find
//    tuple of (min, max) inside single chunk (map).
//  - Combine results of all chunks to single tuple (min, max) - (reduce).

import scala.concurrent.ExecutionContext.Implicits.global
import scala.concurrent._
import scala.concurrent.duration._
import scala.util._
import math.{max, min}

object task2 {
  def _max(a: Int, b: Int): Int = if (a > b) a else b
  def _min(a: Int, b: Int): Int = if (a < b) a else b

  def getMinMax(l: List[Int]): Future[(Int, Int)] = {
    Future(l.reduceLeft(_min), l.reduceLeft(_max))
  }

  def mapReduce(s: List[Int]): Future[(Int, Int)] = {
    val splitted =
      s.grouped(s.length / 10)
        .toSeq // This splits list of Numbers into 10 sequences of numbers - it's first point from plan

    // TODO: Create sequence of features for each chunk, where each future will find tuple of (min, max) inside single chunk (map).
    val minMaxSeq = splitted.map(getMinMax)

    // TODO: Combine results of all chunks to single tuple (min, max) - (reduce).
    Future
      .sequence(minMaxSeq.toList)
      .map(e => (e.map(_._1).reduceLeft(_min), e.map(_._2).reduceLeft(_max)))
  }

  def main(args: Array[String]): Unit = {
    val rNumbers = List.fill(100)(Random.nextInt())

    println(
      (rNumbers.min, rNumbers.max)
    ) // You can check if the result is correct
    val r = mapReduce(rNumbers)

    r onComplete {
      case Success(res) =>
        println(res) // Should be tuple: (MinNumber, MaxNumber)
    }

    Await.ready(r, Duration(10, SECONDS))
  }
}

// TIPS:
// - Use foldLeft to get result tuples from each List/Sequence.
// - Think what should be starting argument for foldLeft! (0, 0) is incorrect
//   think about something else! (Problem of finding minimum/maximum should
//   have been taught on previous semesters, so that shouldn't be that hard).
// - Take a look at types!!! You will have to map from sequence of Ints to
//   Future[(Int, Int)] - THAT HAS TO BE MARKED EXPLICITLY!
// - Take a look at types once more!!! Think what result type of each operation is!
//
// Helpful links (you are allowed to use them on top of other allowed items):
// - https://www.scala-lang.org/api/current/scala/concurrent/Future.html  -> ESPECIALLY METHODS sequence and map
// - https://www.oreilly.com/library/view/scala-reactive-programming/9781787288645/e98e36fe-db95-4bea-98d2-bf2e6eb809e0.xhtml
//
// For some of you in may be good approach to first write program without futures
// and then just add them. That would need changes in original code, which I've
// supplied (with return types and onComplete stuff)
