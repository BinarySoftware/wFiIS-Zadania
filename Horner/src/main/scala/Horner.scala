import scala.collection.immutable._

object Horner {
  def nonEmpty[T](A: List[T]): Boolean = {
    A match {
      case Nil => false
      case _   => true
    }
  }

  /**
    * [[schematHornera(A,x)]]
    *
    * @param A - Lista współczynnikow wielomianu, od
    *            elementu przy najwyzszej potedze
    * @param x - niewiadoma dla ktorej szukane jest
    *            rozwiązanie schematem
    * @return  - wynik dla wielomianu o współczynnikach A i
    *            niewiadomej x obliczony schematem hornera
    *
    * Aby obliczyć wartość NBS w 10 nalezy jako A podać kolejne cyfry
    * NBS od cyfry o najwiekszej wadze, a jako x podać 2
    *
    * Analogicznie mozna postepowac dla kazdego innego systemu
    * pozycyjnego
    *
    * Podana funkcja wykozystuje specyficzne funkcje dla jezyka
    * scala do operowania na tablicach, tj. Tail - zwraca tablice
    * bez 1. elementu, oraz head - 1. element tablicy.
    *
    * Z powodu wywoływania rekurencyjnego funkcji, dochodzi do rekurencyjnego
    * trawersowania tablicy, co powoduje że elementy na jej początku zostaną
    * użyte do obliczeń dopiero na końcu. Aby temu zapobiec funkcja automatycznie
    * odwraca tablicę.
    */
  def schematHornera[T: Numeric](A: List[T], x: T): Option[Double] = {
    def inner(A: List[T], x: T): Double = {
      var s: Double = 0.0
      if (nonEmpty[T](A.tail)) s = inner(A.tail, x)
      s * implicitly[Numeric[T]].toDouble(x) + implicitly[Numeric[T]]
        .toDouble(A.head)
    }

    if (nonEmpty[T](A)) {
      Some(inner(A.reverse, x))
    } else {
      None
    }
  }

  def schematHorneraWhile(A: List[Double], x: Double): Option[Double] = {
    val n : Int = A.length
    var w : Double = A(0) * x
    var i : Int = 1
    while (i <= n-2) {
      w = x * (w + A(i))
      i = i + 1
    }
    Some(w + A(n-1))
  }

  def bezHornera(A: List[Double], x: Double): Option[Double] = {
    def pow(x: Double, p: Double): Double = {
      var s = 1.0
      for (_ <- 1 to p.toInt) {
        s = s*x
      }
      s
    }

    val n : Int = A.length
    var w : Double = 0
    var i : Int = 0
    while (i <= n-1) {
      w = w + A(i)*pow(x,n-1-i)
      i = i + 1
    }
    Some(w)
  }
}

/**
  * Pseudokod bez rekurencji, z while
  *
  * Schemat_Hornera(A,x)
  *   n <- A.count
  *   w <- A[0]*x
  *   i <- 1
  *   while i <= n-2
  *     w <- x*(w+A[i])
  *     i <- i+1
  *   w <- w + A[n-1]
  *   return w
  */
