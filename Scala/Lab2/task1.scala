object task1 {
  def main(args: Array[String]): Unit = {
    args.length match {
      case 2 =>
        val c1: Char = args.apply(0).charAt(0)
        val c2: Char = args.apply(1).charAt(0)
        if (c1.isLetter && c2.isLetter) {
          createSetOfLetters(c1, c2)
        } else {
          println("Please provide ONLY letters.")
        }
      case _ => println("Please provide EXACTLY 2 arguments.")
    }
  }

  def createSetOfLetters(fromChar: Char, toChar: Char): Unit = {
    var f: Char = fromChar.toLower
    var t: Char = toChar.toLower
    if (f.compare(t) > 0) {
      val temp: Char = t
      t = f
      f = temp
    }

    val out = (f to t).toArray.mkString("\n")
    println(out)
  }
}
