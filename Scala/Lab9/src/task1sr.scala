object ConsumerAndConsumed {
  trait Food
  abstract class Animal {
    type food <: Food
    def eat(p: food)
  }

  abstract class Plants extends Food {
    override def toString: String = "Plants"
  }

  trait Meat extends Food {
    override def toString: String = "Meat"
  }

  class Carrot extends Plants {
    override def toString: String = "Carrot"
  }

  class Rabbit extends Animal with Meat {
    override type food = Plants

    override def eat(p: food): Unit = {
      println(this + " crunches the " + p)
    }

    override def toString: String = "Rabbit"
  }

  class Wolf extends Animal {
    override type food = Meat

    override def eat(p: food): Unit = {
      println(this + " tears apart the " + p)
    }

    override def toString: String = "Wolf"
  }

  def main(args: Array[String]): Unit = {
    val c: Plants = new Carrot
    val r         = new Rabbit
    val w         = new Wolf

    r.eat(c)
    w.eat(r)
//    r.eat(r)
//    w.eat(c)
  }
}
