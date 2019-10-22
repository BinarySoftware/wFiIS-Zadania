import scala.collection.immutable._

/**
  * [[Schemat_Hornera(A,x)]]
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
  */
 object Main {
   def nonEmpty[T](A:List[T]): Boolean = {
     A match {
       case Nil => false
       case _   => true
     }
   }

   def schemat_hornera(A:List[Double], x:Double): Option[Double] = {
     def inner(A:List[Double], x:Double): Double = {
       var s : Double = 0.0
       if(nonEmpty[Double](A.tail)) {
         s = inner(A.tail, x)
         println("A : " + A)
       }
       s = s*x + A.head
       s
     }

     if(nonEmpty[Double](A)){
      Some(inner(A,x))
     } else { 
      None 
     }
   }

   def main(args: Array[String]): Unit = {
     val t : List[Double] = List(2.0,3.0,5.0,1.0)
     val x : Double = 3.5
     /* Potrzeba odwrócić listę dla zamierzonego działania head */
     val s : Option[Double] = schemat_hornera(t.reverse,x)
     println("2x^3 + 3x^2 + 5x + 1 dla x = 3.5 to : " + s)
   }
 }
