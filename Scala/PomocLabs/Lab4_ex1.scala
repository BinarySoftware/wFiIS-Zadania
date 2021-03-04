package Lab4

object Lab4_ex1 {
  @scala.annotation.tailrec
  def filterList(
    list: List[String],
    Filter: String => Boolean,
    endOfList: List[String] = List()
  ): List[String] = {
    if (list.isEmpty) return endOfList

    val newList: List[String] =
      if (Filter(list.head)) { endOfList :+ list.head }
      else                   { endOfList              }
    filterList(list.tail, Filter, newList)
  }

  def main(args: Array[String]): Unit = {
    println(
      filterList(List("Hello", "there", "people", "fool"), _.contains("l"))
    )
  }
}
