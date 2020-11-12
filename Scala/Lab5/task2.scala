/**
  * For the second task, you have to create several classes & trait.
  * Make sure you do not repeat methods - you should use polymorphism for that.
  *
  * Formatted is a class, which gets distance as double.
  *
  * Method "toHuman" can print how close you are.
  * (TIP: That method IS NOT included in Formatted class - use polymorphism)
  *
  * distance == 0.0 => Right where you are
  * distance > 0.0 && distance < 10.0 => In your neighborhood
  * distance >= 10.0 => Far away
  * TDistance class counts on construction distance between two points.
  *
  * Formula for distance between two points: sqrt((𝑥2−𝑥1)2+(𝑦2−𝑦1))
  */
object Task2 {
  def main(args: Array[String]): Unit = {
    val x = new Formatted(0.0)
    println(x.toHuman) // Right where you are

    val y = new Formatted(5.0)
    println(y.toHuman) // In your neighborhood

    val z = new Formatted(25.0)
    println(z.toHuman) // Far away
    println(f"${z.rightWhereYouAre()} ${z.inYourNeighborhood()} ${z.farAway()}") // false false true

    val dist = new TDistance((1, 1), (4, 4)) with HumanComparator
    println(dist.toHuman) // In your neighborhood
  }

  trait HumanComparator {
    val distance: Double

    def rightWhereYouAre(): Boolean = distance == 0.0
    def inYourNeighborhood(): Boolean = distance > 0.0 && distance < 10.0
    def farAway(): Boolean = distance >= 10.0

    def toHuman: String = {
      this match {
        case x if x.rightWhereYouAre()   => "Right where you are"
        case x if x.inYourNeighborhood() => "In your neighborhood"
        case _                           => "Far away"
      }
    }
  }

  class Formatted(val distance: Double) extends HumanComparator
  class TDistance(p1: (Int, Int), p2: (Int, Int)) {
    val distance: Double =
      math.sqrt(math.pow(p2._1 - p1._1, 2) + math.pow(p2._2 - p1._2, 2))
  }
}
