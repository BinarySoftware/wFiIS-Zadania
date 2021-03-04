object Ania1 {
//  The goal is to provide a hierarchy of classes/traits allowing to securely
//  define car types and fuel them in "type secure" manner.
//  We have here two hierarchies of classes/traits, one for the Fuel's and one
//  for engines. Each type of Fuel has a volume and a unit.
  trait Fuel {
    val volume: Int
    val unit: String
  }

  class ElectricCharges(val volume: Int) extends Fuel {
    val unit: String = "Ah"
  }
  class Oil(val volume: Int) extends Fuel {
    val unit: String = "Liter"
  }
  class HGas(val volume: Int) extends Fuel {
    val unit: String = "H2 Liter"
  }

  trait Engine {
    type F <: Fuel
  }
  trait ElectricMotor extends Engine {
    override type F = ElectricCharges
  }
  trait Diesel extends Engine {
    override type F = Oil
  }
  trait Hydro extends Engine {
    override type F = HGas
  }

  trait Car extends Engine {
    def addFuel(fuel: F): Unit = {
      print("added ")
      pFuel(fuel)
    }
  }
  trait SUV extends Car {}

  def pFuel(f: Fuel) {
    println(f.volume + " " + f.unit)
  }

//  Method addFuel in the class Engine can not be re-implemented in derived
//  classes. I.e. one implementation in the base Engine trait/class
//  should be sufficient.

  def main(args: Array[String]): Unit = {
    pFuel(new ElectricCharges(10)) // prints just 10 Ah

    val tesla = new Car with ElectricMotor;
    val vw    = new Car with Diesel;
    val honda = new SUV with Hydro;
    tesla.addFuel(new ElectricCharges(100)) // this prints, added 100 Ah
    vw.addFuel(new Oil(30))                 // should print added 300 Liter
    honda.addFuel(new HGas(10))             // should print added 10 H2 Liter
    // any other combination should not compile, specifically
//    vw.addFuel(new ElectricCharges(10)) // should not compile

  }
}
