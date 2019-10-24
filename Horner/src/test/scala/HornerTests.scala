import org.scalatest._
import Horner._
import scala.collection.immutable.List

class HornerTests extends FlatSpec with Matchers {
  def assertExpr[T: Numeric](
    A: List[T],
    x: T,
    result: Option[Double]
  ): Assertion = {
    val output = schematHornera(A, x)
    assert(output == result)
  }

  implicit class TestString[T: Numeric](input: (List[T], T)) {
    def runHorner(str: (List[T], T)): String = {
      s"calculate `$str`"
    }

    private val testBase = it should runHorner(input)

    def ?=(out: Option[Double]): Unit = testBase in {
      assertExpr(input._1, input._2, out)
    }
  }

  //////////////////////////////////////////////////////////////////////////////
  //// Horner Test Suite ///////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////

  (List(1, 0, 1, 0, 1, 0), 2)       ?= Some(42.0)
  (List(0, 0, 1, 0, 1, 0, 1, 0), 2) ?= Some(42.0)
  (List(2.0, 3.0, 5.0, 1.5), 3.5)   ?= Some(141.5)
  (List(), 4)                       ?= None
  (List(0), 4)                      ?= Some(0.0)
  (List(2,0), 4)                    ?= Some(0.0) // Celowy błąd
}
