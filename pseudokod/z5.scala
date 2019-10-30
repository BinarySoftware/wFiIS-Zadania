
Dodaj2Binarne(A,B):[Int] // Dwie tablice zawierające l. binarnie zapisane
  C <- [n+1] // C jest puste o rozmiarze n+1
  for i <- 0 to n-1
    do sum <- A[i] + B[i] + C[i]
    C[i] <- sum % 2
    C[i + 1] <- sum / 2 //wstawia 1 o 1  w lewo gdy wynik to 10 lub 11
  return  C
  
Dodaj2U1(A,B) : ([Int],Bool) //Tablice o dlugosci n, zwraca tuple zawierającąj tablice Int oraz bool gdy wystapil nadmiar/niedomiar
  C <- Dodaj2Binarne(A,B)
  if length[C] > length[A]
    then 
      D <- [n]
      D[0] <- 1 // liczba binarna z 1 na koncu, 0...01
      C <- Dodaj2Binarne(C,D)) // przeniesienie poza znak
      C <- C.tail // porzucenie najstarszego bitu ktory wyszedl poza znak
  overFound  <- false
  if A[0] = B[0] != c[0]
    then overFound <- true
  return (c,overFound)


LinearSearch<T>(A,x:T):Option[Int] // Tablica A o dł. n i szukany element x
  for i <- 0 to n-1
    do
    if A[i] = x 
      then 
        return i
  return Nil


// funkcja wykorzystująca wywołanie rekurencyjne na posortowanej tablicy
// do znalezienia indeksu elementu x w tablicy A przy pomocy dwóch pomocniczych
// funkcji : first i last, slużących do stworzenia nowej tablicy z pierwszych
// lub ostatnich n elementów tablicy wejściowej
BinarySearch(A,x):Option[Int] // tablica A, poczatkowa dl. tablicy, szukany
  m <- floor(length[A]/2)
  if A[m] = x 
    then return m
    else if A[M] < x
      then return BinarySearch(A.first(m),x)
      else if A[M] > x
        then c <- BinarySearch(A.last(length[A]-m),x)
          return length[A] - m + c 
          // musimy dodac dł. drugiej połowy 
          // poczatkowej tablicy aby indeks byl poprawny
        else return Nil
