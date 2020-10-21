import scala.annotation.tailrec

/**
  * Create program which will count number of points, which are inside rectangle created by two different points.
  *
  * Requirements:
  *
  * Create two values, each being a (Int, Int) tuple, which will have X and Y coordinates of points, which will be left bottom and right top corners of rectangle. You can pick (0, 0) and (10, 10) for example.
  * Create list of points (type: List[(Int, Int)]), which will contain points. Make sure that you add some points, which are inside and outside rectangle created by points from bullet number one to check, whether program works correctly.
  * Create tail recursive function (normal recursion = half of points), which will count how many points from List from bullet point 2 are inside rectangle from bullet point 1.
  * Function, which checks, whether point is inside rectangle:
  *
  * def isInside(leftBottomCorner: (Int, Int), rightTopCorner: (Int, Int), point: (Int, Int)): Boolean = point._1 >= leftBottomCorner._1 && point._2 >= leftBottomCorner._2 && point._1 <= rightTopCorner._1 && point._2 <= rightTopCorner._2
  *
  *
  * Hints:
  * Remember about Boolean -> Int conversion.
  * Check what methods List has - they are two, which are very helpful here.
  * Use "@scala.annotation.tailrec" annotation in front of function declaration to make sure it is tail recursive.
  */
object task2 {
  def main(args: Array[String]): Unit = {
    val leftBottomCornerOfRectangle: (Int, Int) = (0, 0)
    val rightTopCornerOfRectangle: (Int, Int) = (10, 10)
    val pointsList
      : List[(Int, Int)] = (0, 0) :: (1, 1) :: (10, 10) :: (11, 0) :: (0, 11) :: Nil

    val result: Int = countPointsInside(
      leftBottomCornerOfRectangle,
      rightTopCornerOfRectangle,
      pointsList
    )

    println(s"Number of points inside rectangle is $result")
  }

  def countPointsInside(leftBottomCorner: (Int, Int),
                        rightTopCorner: (Int, Int),
                        points: List[(Int, Int)]): Int = {
    var counter = 0
    @tailrec def acc(points: List[(Int, Int)]): Unit = {
      if (points.nonEmpty) {
        if (isInside(leftBottomCorner, rightTopCorner, points.head)) {
          counter += 1
        }
        acc(points.tail)
      }
    }
    acc(points)
    counter
  }

  def isInside(leftBottomCorner: (Int, Int),
               rightTopCorner: (Int, Int),
               point: (Int, Int)): Boolean = {
    point._1 >= leftBottomCorner._1 && point._2 >= leftBottomCorner._2 && point._1 <= rightTopCorner._1 && point._2 <= rightTopCorner._2
  }
}
