import scala.collection.immutable._

/**
  * [[schemat_hornera(A,x)]]
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
 object Main {
   def nonEmpty[T](A:List[T]): Boolean = {
     A match {
       case Nil => false
       case _   => true
     }
   }

   def schemat_hornera[T: Numeric](A:List[T], x:T): Option[Double] = {
     def inner(A:List[T], x:T): Double = {
       var s: Double = 0.0
       if(nonEmpty[T](A.tail)) {
         s = inner(A.tail, x)
       }
       s = s*implicitly[Numeric[T]].toDouble(x) + implicitly[Numeric[T]].toDouble(A.head)
       s
     }

     if(nonEmpty[T](A)){
      Some(inner(A.reverse,x))
     } else { 
      None 
     }
   }

   def main(args: Array[String]): Unit = {
     /*
      * Test 1 - powinno dać 141.5
      */
     val t : List[Double] = List(2.0,3.0,5.0,1.5)
     val x : Double = 3.5
     /* Potrzeba odwrócić listę dla zamierzonego działania head */
     val s : Option[Double] = schemat_hornera(t,x)
     println("2x^3 + 3x^2 + 5x + 1.5 dla x = 3.5 to : " + s)

     /*
      * Test 2 - liczba binarna 101010 - 42
      */
     val bin : List[Int] = List(1,0,1,0,1,0)
     val dec : Option[Double] = schemat_hornera(bin,2)
     println("101010 : " + dec)

     /*
      * Test 3 - brak elementow w liscie
      */
     val b : Option[Double] = schemat_hornera(List(),x)
     println("f puste od x = 3.5 : " + b)
   }
 }

 /*
  * Pseudokod bez rekurencji, z while
  *
  * Schemat_Hornera(A,x)
  *   n <- A.count
  *   w <- A[n-1]*x
  *   i <- 0
  *   while i <= n-2
  *     w <- x*(w*A[n-1-i])
  *     i <- i+1
  *   w <- w + A[0] 
  *   return w
  */
