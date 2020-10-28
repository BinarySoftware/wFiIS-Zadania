object task2 {
  class ToDoItem(what: String, when: String, var done: Boolean = false) {
    override def toString: String = s"$what\t- till $when\t| DONE: $done"
    def markAsDone(): Unit = done = true
  }

  class ToDoList() {
    var list: List[ToDoItem] = Nil
    def +(item: ToDoItem): Unit = list = list :+ item
    def markAsDone(index: Int): Unit = list(index).markAsDone()
    def removeDone(): Unit = list = list.filter(_.done == false)
    override def toString: String = list.map(_.toString).mkString("\n")
  }

  def main(args: Array[String]): Unit = {
    val toDoList = new ToDoList()

    toDoList + new ToDoItem("Clean carpet", "2020-11-01")
    toDoList + new ToDoItem("Wash dishes", "2020-11-02")
    toDoList + new ToDoItem("Learn Scala", "2020-10-28")

    println(toDoList)
    println()

    toDoList.markAsDone(0)

    println(toDoList)
    println()

    toDoList.removeDone()

    println(toDoList)
    println()
  }
}
