/**
  * Inspiration:
  * flange :: IO ()
  * flange = traverse_ putTextLn result
  * where
  * result :: [Text]
  * result = runST do
  * let input = "Hello World"
  * var <- newSTRef (input, [])
  * loop (T.length input) var
  *
  * loop :: Int -> STRef s (Text, [Text]) -> ST s ([Text])
  * loop 0 var  = reverse . snd <$> readSTRef var
  * loop n var = do
  * (txt0, log) <- readSTRef var
  * let (h, T.map succ -> t) = T.splitAt (n-1) txt0
  * txt1 = h <> t
  * out = txt0 <> " -> " <> txt1
  * modifySTRef' var $ const (txt1, out : log)
  * loop (n-1) var
  */

object Flange {
  def flange(value: String, isLogging: Boolean = false): String = {
    val flanged = value.toCharArray
    for (i <- value.length - 1 to 0 by -1) {
      if (isLogging) println(flanged.mkString("") + " -> ")
      for (j <- value.length - 1 to i by -1) {
        flanged(j) = (flanged(j) + 1).toChar
      }
      if (isLogging) println(flanged.mkString(""))
    }
    flanged.mkString("")
  }

  def deflange(value: String, isLogging: Boolean = false): String = {
    val deflanged = value.toCharArray
    for (i <- value.length - 1 to 0 by -1) {
      if (isLogging) print(deflanged.mkString("") + " -> ")
      for (j <- value.length - 1 to i by -1) {
        deflanged(j) = (deflanged(j) - 1).toChar
      }
      if (isLogging) println(deflanged.mkString(""))
    }
    deflanged.mkString("")
  }
}

object Main {
  import Flange._
  def main(args: Array[String]): Unit = {
    val input = "hello world"
    println("===== Input =====")
    println(input)
    println("===== Flange =====")
    val fl = flange(input)
    println(fl)
    println("===== Deflange =====")
    val de = deflange(fl)
    println(de)
  }
}
