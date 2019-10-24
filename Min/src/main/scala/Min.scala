import scala.collection.immutable._
import Ordering.Implicits._
import Numeric.Implicits._

object Min {
  def nonEmpty[T](A: List[T]): Boolean = {
    A match {
      case Nil => false
      case _   => true
    }
  }

  def min2[T: Numeric](a: T, b: T): T = {
    if ( a < b ) a else b
  }

  def minRecursive[T: Numeric](A: List[T]): Option[T] = {
    def inner(A: List[T]): T = {
      if (nonEmpty[T](A.tail)) {
        min2(A.head, inner(A.tail))
      } else {
        A.head
      }
    }

    if (nonEmpty[T](A)) {
      Some(inner(A))
    } else {
      None
    }
  }
}
