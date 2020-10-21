/**
  * Conditions:
  *
  * Each rectangle is represented like this: (lengthOfFirstSide, lengthOfSecondSide) (tuple)
  * We do not consider negative numbers
  * Your goal is:
  *
  * Show me three ways how to create list of rectangles (just in plain code, I mean different operators and use of list constructor)
  * Create function, which will return list of rectangles, where area is bigger than 2nd argument (first one is list created in goal number 1)
  * Create function, which prints one rectangle like "(lengthOfFirstSide, lengthOfSecondSide) => area: area"
  * Use both methods to print list of rectangles, where area is bigger than your lucky number
  */
object task2 {
  def main(args: Array[String]): Unit = {
    val _: List[(Int, Int)] = List((1, 1), (1, 2))
    val _: List[(Int, Int)] = List.fill(4)((3, 2))
    val _: List[(Int, Int)] = List.tabulate(5)(n => (n, n))
    val list: List[(Int, Int)] = (6, 3) :: (2, 3) :: (1, 1) :: (9, 6) :: Nil

    val filteredList = getListOfRectangles(list, 7)
    for (e <- filteredList) printRectange(e)
  }

  def getListOfRectangles(list: List[(Int, Int)],
                          number: Int): List[(Int, Int)] = {
    val filtered = list.filter(el => calculateArea(el) > number)
    filtered
  }

  def printRectange(rect: (Int, Int)): Unit = {
    val area = calculateArea(rect)
    println(s"(${rect._1}, ${rect._2}) => area : $area")
  }

  final def calculateArea(rect: (Int, Int)): Int = rect._1 * rect._2
}
