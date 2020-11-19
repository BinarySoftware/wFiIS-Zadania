/** Today we will be working at McDonald's!
  * Make sure that following code returns following output with several notices
  * (you have to use abstract class(es), trait(s) and class(es) with proper inheritance):
  *
  * Price of Fries / Coke in large set is 1.5 normal price
  * Normal price of fries = 5, normal price of coke = 4
  * BigMac = 10, McWrap = 9
  * There should be only two methods, which makes fries/coke large
  * (TIP: One is connected with name, another one with price)
  *
  * Output:
  *
  * McSet with BigMac normal fries normal coke 19.0
  * Large McSet with BigMac large fries large coke 23.5
  * Large McSet with McWrap large fries 16.5
  */
object task1 {
  trait Food {
    val isLarge: Boolean = false
    def name: String     = ""
    def price: Double    = 0
  }

  trait Fries extends Food {
    override def name: String = {
      if (isLarge) { super.name + "large Fries "  }
      else         { super.name + "normal Fries " }
    }
    override def price: Double = {
      if (isLarge) { super.price + 5 * 1.5 }
      else         { super.price + 5       }
    }
  }
  trait Coke extends Food {
    override def name: String = {
      if (isLarge) { super.name + "large Coke "  }
      else         { super.name + "normal Coke " }
    }
    override def price: Double = {
      if (isLarge) { super.price + 4 * 1.5 }
      else         { super.price + 4       }
    }
  }
  trait BigMac extends Food {
    override def name: String  = super.name + "BigMac "
    override def price: Double = super.price + 10
  }
  trait McWrap extends Food {
    override def name: String  = super.name + "McWrap "
    override def price: Double = super.price + 9
  }

  class NormalMcSet extends Food {
    override def name: String  = "McSet with " + super.name
    override def price: Double = super.price
  }

  class LargeMcSet extends NormalMcSet {
    override val isLarge: Boolean = true
    override def name: String     = "Large " + super.name
    override def price: Double    = super.price
  }

  def main(args: Array[String]): Unit = {
    val firstMcSet      = new NormalMcSet with BigMac with Fries with Coke
    val firstMcSetLarge = new LargeMcSet with BigMac with Fries with Coke
    val secondMcSet     = new LargeMcSet with McWrap with Fries

    println(firstMcSet.name + " " + firstMcSet.price)
    println(firstMcSetLarge.name + " " + firstMcSetLarge.price)
    println(secondMcSet.name + " " + secondMcSet.price)
  }
}
