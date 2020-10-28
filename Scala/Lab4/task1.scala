import scala.annotation.tailrec

object task1 {
  def main(args: Array[String]): Unit = {
    val predicate = (x: Int) => x % 2 == 0
    println(
      partition(
        list = List(1, 2, 3, 4, 5, 6, 7, 8, 9, 10),
        predicate = predicate
      )
    )
  }

  def partition(list: List[Int], predicate: Int => Boolean): List[List[Int]] = {
    var trueList: List[Int] = Nil
    var falseList: List[Int] = Nil
    @tailrec def acc(inList: List[Int]): Any = {
      if (inList.isEmpty) { return }
      predicate(inList.head) match {
        case true  => trueList = trueList :+ inList.head
        case false => falseList = falseList :+ inList.head
      }
      acc(inList.tail)
    }
    acc(list)
    List(trueList, falseList)
  }
}
