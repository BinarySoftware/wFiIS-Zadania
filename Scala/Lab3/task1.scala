/**
  * Create program which will be able to solve mathematical equations
  * (just addition, substraction, multiplication and division) from string form.
  *
  * Requirements:
  *
  * You have to have 4 functions, each accepting two integers and returning one integer,
  * which is result of mathematical operation. Division operates on Integers and returns Integer too.
  *
  * Keep these functions in Map[Char, (Int, Int) => Int], where char is sign of operation
  * and function is one of the functions from point number 1.
  *
  * You have to have one function called "solveEquation" which accepts string with
  * equation as parameter and can determinate and solve all equation types
  * (there's method in String class, which divide string to Array[String] by character,
  * use REPL to find it, it should be rather easy :) ).
  * So in the nutshell it has to divide string into 3 pieces
  * (two Ints and one char, which determines the operation type),
  * pick operation from Map, use the function returned by map on two Ints and return the result.
  */
object task1 {
  def main(args: Array[String]): Unit = {
    val equation1 = "2 + 2"
    assert(solveEquation(equation1) == 4)
    println(s"Answer: ${solveEquation(equation1)}")

    val equation2 = "2 - 2"
    assert(solveEquation(equation2) == 0)
    println(s"Answer: ${solveEquation(equation2)}")

    val equation3 = "2 * 2"
    assert(solveEquation(equation3) == 4)
    println(s"Answer: ${solveEquation(equation3)}")

    val equation4 = "2 / 2"
    assert(solveEquation(equation4) == 1)
    println(s"Answer: ${solveEquation(equation4)}")
  }

  def solveEquation(equation: String): Int = {
    val map = Map[Char, (Int, Int) => Int](
      '+' -> add,
      '-' -> sub,
      '*' -> mul,
      '/' -> div
    )

    val arr = equation.split(" ")
    val a = arr(0).toInt
    val b = arr(2).toInt
    val operand = arr(1).charAt(0)
    map(operand)(a, b)
  }

  def add(a: Int, b: Int): Int = { a + b }
  def sub(a: Int, b: Int): Int = { a - b }
  def mul(a: Int, b: Int): Int = { a * b }
  def div(a: Int, b: Int): Int = { if (b == 0) { 0 } else { a / b } }
}
