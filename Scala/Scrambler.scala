import scala.util.Random

object Scrambler {
  val space: String   = " "
  val newLine: String = "\n"
  val inter: String   = "!,.?"

  def scrambleWord(word: String): String = {
    if (word.length <= 2) {
      word
    } else {
      var str       = space
      val firstElem = word.head
      var lastElem  = word.last.toString
      var middle    = word.tail.dropRight(1).toList
      if (inter.contains(word.last)) {
        if (word.length <= 3) {
          return word
        }
        lastElem = word.takeRight(2)
        middle   = word.tail.dropRight(2).toList
      }
      val shuffled = Random.shuffle(middle).mkString("")
      str = firstElem.toString.concat(shuffled).concat(lastElem)
      str
    }
  }

  def scrambleTailrec(list: List[String]): List[String] = {
    var l: List[String] = Nil
    @scala.annotation.tailrec def acc(list: List[String]): Unit = {
      if (list.isEmpty) { return }
      l = l :+ scrambleWord(list.head)
      acc(list.tail)
    }
    acc(list)
    l
  }

  def scramble(string: String): String = {
    val listOfWords          = string.replaceAll(newLine, space).split(space).toList
    val scrambledListOfWords = scrambleTailrec(listOfWords)
    var out                  = ""
    for (iter <- scrambledListOfWords.indices) {
      if (iter % 10 == 0) {
        out = out + newLine + scrambledListOfWords(iter)
      } else {
        out = out + space + scrambledListOfWords(iter)
      }
    }
    out
  }

  ///===========================================================================
  ///===========================================================================
  ///===========================================================================
  def main(args: Array[String]): Unit = {
    val str =
      """Did you know how powerful your brain is? 
        |Scientists at californian university discovered that
        |you can easily read shuffled words, as long as their first and last
        |letter stay in their places. And can you read this?""".stripMargin
    val str2 =
      """Czy wiesz jaką potęgą jest twój umysł? 
        |Naukowcy z uniwersytetu w cambridge odkryli, że kolejność liter w słowie
        |może nie mieć aż tak dużego znaczenia, gdyż twój mózg nie czyta słów 
        |litera po literze, natomiast szuka znanych już modeli słów, do których 
        |stara się dopasować to co widzi, niczym model uczenia maszynowego 
        |sprawdza prawdopodobieństwo dangeo zdarzenia, i na tej podstawie ogłasza
        |werdykt.
        |""".stripMargin
    print(scramble(str))
    println("\n\n\n")
    print(scramble(str2))
    println("\n\n\n")
  }
}
