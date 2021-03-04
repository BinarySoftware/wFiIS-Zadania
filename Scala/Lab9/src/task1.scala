import math.{max, min}

/**
  * NOTE: Please remember to add "import math.{ min, max }" at the top of file,
  * to make sure examples from point 2 works!
  *
  * NOTE: You should use only higher order functions like map, reduce, foldLeft,
  *       zip, filter etc. No for/foreach/yield/var etc.
  *
  * Create two functions, according to descriptions:
  *
  * Function should accept list of integers and return list of integers, which
  * are unique in the first list. Unique = appear just once.
  * THIS IS NOT LIST WITHOUT DUPLICATES,
  * THIS IS LIST OF ITEMS, WHICH APPEAR JUST ONCE IN ORIGINAL LIST!
  *
  * Function should accept two lists of integers (of the same size) and partial function.
  * Partial function should accept tuple of integers and return just one integer.
  * You should take pairs (first item of pair comes from first list, second from second)
  * and supply them to partial function. Result of that shall be list of integers,
  * which should be returned from the function.
  */
object task1 {

  def unique(l: List[Int]): List[Int] =
    l.groupBy(identity)
      .map(e => (e._1, e._2.length))
      .filter(_._2 == 1)
      .keys
      .toList

  def mergePairs(
    l1: List[Int],
    l2: List[Int],
    method: ((Int, Int)) => Int
  ): List[Int] = {
    val l = l1 zip l2
    l.map(method)
  }

  def main(args: Array[String]): Unit = {
    println(unique(List(1, 1, 5, 6, 3, 5, 8, 9, 10, 8))) // List(10, 6, 9, 3)

    println(
      mergePairs(List(1, 5, 9, 10), List(0, 4, 10, 11), x => max(x._1, x._2))
    ) // List(1, 5, 10, 11)

    println(
      mergePairs(List(1, 5, 9, 11), List(0, 4, 10, 8), x => min(x._1, x._2))
    ) // List(0, 4, 9, 8)
  }
}
