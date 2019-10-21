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
  *
  * oznaczenie @tailrec inforrmuje kompilator iz ma do czynienia z
  * rekurencją ogonową, w celu zażegnania problemu z JVM i nadmiarem
  * na stosie ( stack overflow )
  *
  */
 object Main {
   def nonEmpty[A](A:List[T]): Bool = {
     A match {
       case Nil => false
       case _   => true
     }
   }

   def schemat_hornera(A:List[Double], x:Double): Option[Double] = {
     @tailrec def inner(A:List[Double], x:Double): Double = {
       var s : Double = 0.0
       if(A.length > 1) {
         s = Schemat_Hornera(A.tail, x)
       }
       s*x + A.head
     }

     if(nonEmpty(A)){
      Some(inner(A,x))
     } else { 
      None 
     }
   }
 }
