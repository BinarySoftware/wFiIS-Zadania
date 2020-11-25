object task2 {
  def main(args: Array[String]): Unit = {
    val g = new Grosz
    val z = new Zlotowka

    val pe = new Penny
    val po = new Pound

    val polishCashieer  = new PolishCashieer("Ania")
    val englishCashieer = new EnglishCashieer("John")

    polishCashieer.getPayment(g)
    polishCashieer.getPayment(z)

//    polishCashieer.getPayment(pe) // when uncommented - compilation error
//    polishCashieer.getPayment(po) // when uncommented - compilation error

    englishCashieer.getPayment(pe)
    englishCashieer.getPayment(po)

    //     englishCashieer.getPayment(g) // when uncommented - compilation error
    //     englishCashieer.getPayment(z) // when uncommented - compilation error
  }
}

trait MonetarySystem
trait PolishMonetarySystem extends MonetarySystem
class Grosz                extends PolishMonetarySystem
class Zlotowka             extends PolishMonetarySystem

trait EnglishMonetarySystem extends MonetarySystem
class Penny                 extends EnglishMonetarySystem
class Pound                 extends EnglishMonetarySystem

trait Cashieer {
  type T <: MonetarySystem
  def getPayment(e: T): Unit = {
    println(
      this.getClass.getCanonicalName + " got payment in " + e.getClass.getCanonicalName
    )
  }
}

class PolishCashieer(n: String) extends Cashieer {
  type T = PolishMonetarySystem
}

class EnglishCashieer(n: String) extends Cashieer {
  type T = EnglishMonetarySystem
}
