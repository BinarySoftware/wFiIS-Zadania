// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.
// Prosze napisac funkcje tworzace i operujace na  ciagach Fibonacciego (ciag liczb naturalnych, gdzie F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2)).

// Pliku main.cpp, nie wolno modyfikowac.

// CMakeLists.txt dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Lab01. Program nalezy kompilowac z flagami -Wall -g.

// Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
// ani żadnych innych materiałów (w tym własnych wcześniej
// przygotowanych plików)

//Rozwiązanie należy przesłać na UPEL.

//Powodzenia!
 
#include <iostream>
#include "funkcje.h"

int main() {
  const int n0 = wczytajLiczbeWyrazow();
  std::cout << "Liczba w systemie binarnym: ";
  wypiszBinarnie(n0);
  std::cout << "\n";
  
  const int* ciag0 = inicjalizujCiagFibonacciego(n0);
  wypisz(ciag0,n0);

  const int n1 = wczytajLiczbeWyrazow();
  const int* ciag1 = inicjalizujCiagFibonacciego(n1);
  wypisz(ciag1,n1);

  suma(ciag0,n0);
  iloczyn(ciag0,n0);
  suma(ciag0,n0,ciag1,n1);
  max(ciag0,n0,ciag1,n1);
  
  UsunCiag(ciag0);
  UsunCiag(ciag1);
  return 0;
}
//Output
//Podaj n: 5
//Liczba w systemie binarnym: 101
//(0, 1, 1, 2, 3, 5)
//Podaj n: 6
//(0, 1, 1, 2, 3, 5, 8)
//suma: 12
//iloczyn: 30
//suma dwoch ciagow: 32
//maksimum: 8 (ciag1)

