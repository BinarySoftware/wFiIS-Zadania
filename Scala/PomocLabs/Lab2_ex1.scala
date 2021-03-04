package Lab2
import scala.math.Pi

object Lab2_ex1 {
  // Ex. 1 Basics

  def traverseArray(x: Range, y: Range)(closure: (Int, Int) => Unit): Unit = {
    for {
      i <- x
      j <- y
    } closure(i, j)
  }

  def print_tab(x: Array[Array[Int]]): Unit = {
    def closure(i: Int, j: Int): Unit = {
      if (j == 0) print("| ")
      print(x(i)(j) + " ")
      if (j == x(i).length - 1) println("|")
    }
    traverseArray(x.indices, x(0).indices)(closure)
  }

  def get_2_arrays(x: Array[Array[Int]]): List[Array[Int]] = {
    val rows_sum     = new Array[Int](x.length)
    val cols_sum     = new Array[Int](x(0).length)
    val x_transposed = x.transpose

    for (i <- x.indices) rows_sum.update(i, x(i).sum)
    for (j <- x_transposed.indices) cols_sum.update(j, x_transposed(j).sum)

    List(rows_sum, cols_sum)
  }
  def transpose(x: Array[Array[Int]]): Array[Array[Int]] = {
    x.transpose
  }
  def merge_arrays(
    x: Array[Array[Int]],
    y: Array[Array[Int]]
  ): Array[Array[Int]] = {
    val xy = Array.ofDim[Int](x.length, x(0).length)
    def closure(i: Int, j: Int): Unit = {
      xy(i)(j) = scala.math.max(x(i)(j), y(i)(j))
    }
    traverseArray(x.indices, x(0).indices)(closure)
    xy
  }

  def main(args: Array[String]): Unit = {
    // Testing...
    val x = Array.ofDim[Int](4, 5)
    def closure(i: Int, j: Int): Unit = {
      x(i)(j) = i + j
    }
    traverseArray(0 until 4, 0 until 5)(closure)

    println("Ex. 1")
    print_tab(x)

    println("Ex. 2")
    val l = get_2_arrays(x)
    l(0).foreach(x => print(f"$x "))
    println()
    l(1).foreach(x => print(f"$x "))
    println()

    println("Ex. 3")
    val x_transposed = transpose(x)
    print_tab(x_transposed)

    println("Ex. 4")
    val y = Array.ofDim[Int](4, 5)
    def closure2(i: Int, j: Int): Unit = {
      x(i)(j) = i + j + 1
    }
    traverseArray(0 until 4, 0 until 5)(closure2)
    for (i <- 0 until 4) y(i)(i) = 9
    y(2)(0) = 4
    y(3)(1) = 7

    val xy = merge_arrays(x, y)
    print_tab(xy)
  }
}
