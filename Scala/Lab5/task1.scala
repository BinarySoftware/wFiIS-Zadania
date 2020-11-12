object Task1 {
  object SDistance extends Enumeration {
    val Kilometers, Meters, Centimeters = values
  }
  case class SDistance(var kilometers: Int,
                       var meters: Int,
                       var centimeters: Int) {
    def add(len: Int, tp: SDistance.ValueSet): SDistance = {
      tp match {
        case SDistance.Kilometers =>
          SDistance(this.kilometers + len, this.meters, this.centimeters)
        case SDistance.Meters =>
          SDistance(this.kilometers, this.meters + len, this.centimeters)
        case SDistance.Centimeters =>
          SDistance(this.kilometers, this.meters, this.centimeters + len)
      }
    }

    def <(secondDistance: SDistance): Boolean = {
      secondDistance > this
    }

    def >(secondDistance: SDistance): Boolean = {
      val d1 = this.kilometers * 100000 + this.meters * 100 + this.centimeters
      val d2 = secondDistance.kilometers * 100000 + secondDistance.meters * 100 + secondDistance.centimeters
      d1 > d2
    }

    override def toString: String = {
      "Kilometers: " + kilometers + ", Meters: " + meters + ", Cenitmeters: " + centimeters
    }
  }

  def main(args: Array[String]): Unit = {
    val firstDistance = SDistance(2, 2, 2)
    val secondDistance = SDistance(2, 2, 2)
    val thirdDistance = SDistance(2, 2, 3)
    val fourthDistance = SDistance(2, 2, 1)

    println("Distances:")
    println(firstDistance) // Kilometers: 2, Meters : 2, Centimeters: 2
    println(secondDistance) // Kilometers: 2, Meters : 2, Centimeters: 2
    println(thirdDistance) // Kilometers: 2, Meters : 2, Centimeters: 3
    println(fourthDistance) // Kilometers: 2, Meters : 2, Centimeters: 1

    println("2:")
    println(firstDistance == secondDistance) // true
    println(firstDistance != secondDistance) // false
    println(firstDistance > secondDistance) // false
    println(firstDistance < secondDistance) // false

    println("3:")
    println(firstDistance == thirdDistance) // false
    println(firstDistance != thirdDistance) // true
    println(firstDistance > thirdDistance) // false
    println(firstDistance < thirdDistance) // true

    println("4:")
    println(firstDistance == fourthDistance) // false
    println(firstDistance != fourthDistance) // true
    println(firstDistance > fourthDistance) // true
    println(firstDistance < fourthDistance) // false

    val fifthDistance = firstDistance.add(2, SDistance.Kilometers) // here you have to be able to add also meters or centimeters
    println(fifthDistance) // Kilometers: 4, Meters: 2, Centimeters: 2
  }
}
