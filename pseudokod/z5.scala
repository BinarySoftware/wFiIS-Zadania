
Dodaj2Binarne(A,B) // Dwie tablice zawierające l. binarnie zapisane
  C <- [n + 1] // C jest puste o rozmiarze n+1
  for i <- 1 to n
    do sum <- A[i] + B[i] + C[i]
    C[i] <- sum % 2
    C[i + 1] <- sum / 2 //wstawia 1 o 1  w lewo gdy wynik to 10 lub 11
  return  C

Dodaj2U1(A,B) : ([Int],Bool) //Tablice o dlugosci n, zwraca tuple zawierającąj tablice Int oraz bool gdy wystapil nadmiar/niedomiar
  c <- Dodaj2Binarne(A,B)
  if length[d] > length[A]
    then 
      d <- [n]
      d[n] <- 1 // pusta tablica o 1 na koncu
      c <- Dodaj2Binarne(c,d) // przeniesienie poza znak
  e <- false
  if A[0] = B[0] != c[0]
    then e <- true
  return (c,e)

LinearSearch(A,x) // Tablica A o dł. n i szukany element x
  s <- Nil
  for i <- 0 to n-1
    do
    if A[i] = x 
      then 
        s <- i
        break // moze zostac zastosowane po pierwszym znalezionym X aby zredukowac ilosc powtorzen petli
  return s

BinarySearch(A,x) // analogicznie, lecz z posortowaną tablicą
  
