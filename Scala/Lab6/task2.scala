/** Create class hierarchy & use match/case to make sure following code
  * works and returns output written below:
  *
  * Result: 0.0
  * Adding 1.0
  * Subtracting 1.0
  * Result: 0.0
  * Unknown / not allowed operation
  * Result: 0.0
  * Adding 1.0
  * Multiplying by 5.0
  * Result: 5.0
  * Dividing by 2.0
  * Result: 2.5
  * Unknown / not allowed operation
  * Result: 2.5
  */
object task2 {
  class EquationSolver() {
    var result      = 0.0
    val unknownText = "Unknown/not allowed operation"

    def <<(opr: Any): EquationSolver = {
      opr match {
        case o: Operation =>
          o match {
            case Addition(e) =>
              println("Adding " + e)
              result += e
            case Division(e) if e != 0 =>
              println("Dividing by " + e)
              result /= e
            case Multiplication(e) =>
              println("Multiplying by " + e)
              result *= e
            case Subtraction(e) =>
              println("Subtracting " + e)
              result -= e
            case _ => println(unknownText)
          }
        case _ => println(unknownText)
      }
      this
    }

    override def toString: String = "Result: " + result
  }
  trait Operation {
    val e: Int
  }
  case class Addition(e: Int)       extends Operation
  case class Subtraction(e: Int)    extends Operation
  case class Division(e: Int)       extends Operation
  case class Multiplication(e: Int) extends Operation

  def main(args: Array[String]) = {

    val s = new EquationSolver()
    println(s)
    s << Addition(1) << Subtraction(1)
    println(s)
    s << Division(0)
    println(s)
    s << Addition(1) << Multiplication(5)
    println(s)
    s << Division(2)
    println(s)
    s << List[Int](1)
    println(s)

  }

}
