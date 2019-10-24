import org.scalatest._
import Horner._
import scala.collection.immutable.List

class HornerTests extends FlatSpec with Matchers {
  def assertRec[T: Numeric](
    A: List[T],
    x: T,
    result: Option[Double]
  ): Assertion = {
    val hornerRecursive = schematHornera(A, x)
    assert(hornerRecursive == result)
  }

  def assertWhile(
    A: List[Double],
    x: Double,
    result: Option[Double]
  ): Assertion = {
    val hornerWhile = schematHorneraWhile(A, x)
    assert(hornerWhile == result)
  }

  def assertNoHorner(
    A: List[Double],
    x: Double,
    result: Option[Double]
  ): Assertion = {
    val noHorner = bezHornera(A, x)
    assert(noHorner == result)
  }

  implicit class TestHornerRec[T: Numeric](input: (List[T], T)) {
    def runHorner(str: (List[T], T)): String = {
      s"calculate (recursively) `$str`"
    }

    private val testBase = it should runHorner(input)

    def ?=(out: Option[Double]): Unit = testBase in {
      assertRec(input._1, input._2, out)
    }
  }

  implicit class TestHornerWhile(input: (List[Double], Double)) {
    def runHorner(str: (List[Double], Double)): String = {
      s"calculate (while) `$str`"
    }

    private val testBase = it should runHorner(input)

    def ?==(out: Option[Double]): Unit = testBase in {
      assertWhile(input._1, input._2, out)
    }
  }

  implicit class TestNoHorner(input: (List[Double], Double)) {
    def runNoHorner(str: (List[Double], Double)): String = {
      s"calculate (No horner) `$str`"
    }

    private val testBase = it should runNoHorner(input)

    def ?===(out: Option[Double]): Unit = testBase in {
      assertNoHorner(input._1, input._2, out)
    }
  }

  //////////////////////////////////////////////////////////////////////////////
  //// Horner Test Suite ///////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////

  (List(1, 0, 1, 0, 1, 0), 2)     ?= Some(42.0)
  (List(2.0, 3.0, 5.0, 1.5), 3.5) ?= Some(141.5)
  (List(0.0), 4.0)                ?= Some(0.0)
  (List(2, 0), 4)                 ?= Some(8.0)
  (List(0, 0, 1, 0, 1, 0, 1, 0), 2) ?= Some(42.0)
  (List(), 4)                       ?= None
  (List(0), 4)                      ?= Some(0.0)
//  (List(3, 0), 4)                 ?= Some(0.0) // Celowy błąd

//  (List(1.0, 0.0, 1.0, 0.0, 1.0, 0.0), 2.0)  ?== Some(42.0)
//  (List(2.0, 3.0, 5.0, 1.5), 3.5)            ?== Some(141.5)
//  (List(0.0), 4.0)                           ?== Some(0.0)
//  (List(2.0, 0.0), 4.0)                      ?== Some(8.0)

//  (List(1.0, 0.0, 1.0, 0.0, 1.0, 0.0), 2.0)  ?=== Some(42.0)
//  (List(2.0, 3.0, 5.0, 1.5), 3.5) ?=== Some(141.5)
//  (List(0.0), 4.0) ?=== Some(0.0)
//  (List(2.0, 0.0), 4.0) ?=== Some(8.0)
}
