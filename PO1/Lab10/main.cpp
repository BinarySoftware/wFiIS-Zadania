/*
  Tematem zadania sa szablony funkcji ze specjalizacją. Zastosowane sa tutaj szablony o argumentach, ktore nie sa typami. Małą trudność moze sprawic przekazanie tablicy o znanym rozmiarze jako argument funkcji.
 
  Wszystkie kody funkcji mają być poza klasą - funkcje w klasie -2 punkty
  Zadanie jest krótkie, więc dokumentacja ma być dokładnie zrobiona w formacie doxygen.
 */

#include <iostream>
#include "Num.h"
int main() {

  int a[6] = {2,4,5,7,9,10};
  const double aS1 = num::srednia<int>(a, 6);
  const double aS2 = num::srednia(a);
  std::cout << "Srednia z int: " << aS1 << " " << aS2 << std::endl;

  float d[5] = {0, 0.7, 9.1, 3.1, 2.2};
  const double dS1 = num::srednia<float>(d, 5);
  const double dS2 = num::srednia(d);
  std::cout << "Srednia z float: " << dS1 << " " << dS2 << std::endl;

  const float e[5] = {0, 0.7, 9.1, -3.1};
  const double eS1 = num::srednia<float>(e, 5);
  const double eS2 = num::srednia(e);
  std::cout << "Srednia z const float: " << eS1 << " " << eS2 << std::endl;

  const bool wp  = num::czyWszystkiePierwsze<2,6>(a); // wszystkie miedzy indeksami [2, 6]
  const bool wnp = num::czyWszystkiePierwsze<2,4>(a); // wszystkie miedzy indeksami [2, 4]
  std::cout << "Czy wszystkie liczby w zakresie pierwsze: " << num::text(wp) << " " << num::text(wnp) << std::endl;
  bool wnb = num::czyWszystkiePierwsze<4,2>(a); // błąd
  wnb = num::czyWszystkiePierwsze<4,12>(a); //błąd
}


/* wynik
Srednia z int: 6.16667 6.16667
Srednia z float: 3.02 3.02
Srednia z const float: 1.34 1.34
Czy wszystkie liczby w zakresie pierwsze: FALSE TRUE
Nieprawidlowy zakres!
Nieprawidlowy zakres!
*/
 