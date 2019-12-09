import org.scalatest._
import Min._
import scala.collection.immutable.List

class MinTests extends FlatSpec with Matchers {
  def assertExpr[T: Numeric](
    A: List[T],
    result: Option[Double]
  ): Assertion = {
    val output = minRecursive(A)
    assert(output == result)
  }

  implicit class TestString[T: Numeric](input: List[T]) {
    def runMin(l: List[T]): String = {
      s"find minimum in `$l`"
    }

    private val testBase = it should runMin(input)

    def ?=(out: Option[Double]): Unit = testBase in {
      assertExpr(input, out)
    }
  }

  //////////////////////////////////////////////////////////////////////////////
  //// Horner Test Suite ///////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////

  List(1, 0, 1, 0, 1, 0)          ?= Some(0)
  List(0, 0, 0, 0)                ?= Some(0)
  List(2.0, 3.0, 5.0, 1.5, 0.5)   ?= Some(0.5)
  List(2,0)                       ?= Some(0)
  List(5,4,3,2,7,6)               ?= Some(2)
  List(2.0, 2.1,2.5,1)            ?= Some(1)
}
