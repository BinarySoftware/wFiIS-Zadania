object lab69 {
  class stream(ser: String) {
    override def toString: String = ser

    def deseialize(): Unit = {
      val listPattern   = "(List)(\\(*)".r
      val stringPattern = "(String)(?<=\\(*)(?=\\))".r
      val intPattern    = "(Int)(?<=\\(*)(?=\\))".r
      val doublePattern = "(Double)(?<=\\(*)(?=\\))".r

      ser match {
        case listPattern(x) => println("FOO")
        case x              => println(x)
      }
    }
  }

  object stream {
    def apply(values: List[Any]): stream =
      new stream("List(" + applyRc(values) + ")")

    def applyRc(values: List[Any]): String = {
      values match {
        case Nil      => ""
        case x :: Nil => matchType(x)
        case x :: xs  => matchType(x) + ", " + applyRc(xs)
      }
    }

    def matchType(value: Any): String = {
      value match {
        case x: String => s"String($x)"
        case x: Int    => s"Int($x)"
        case x: Double => s"Double($x)"
        case x: Float  => s"Float($x)"
        case x         => s"Any($x)"
      }
    }
  }

  def main(args: Array[String]): Unit = {
    val l        = List(1, "hello", 2.56, 0x45, "key")
    val streamed = stream(l)
    println(streamed)
    streamed.deseialize()
  }
}
