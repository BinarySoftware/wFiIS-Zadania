/*
 Prosze napisac klase Worek, ktora dziala jak kolejka LIFO
 (Last In, First Out; ostatni na wejściu, pierwszy na wyjściu).
 W kolejce beda przechowywane obiekty typu Prezent, ktore zawieraja
 informacje o cenie. Dodatkowo dostepna jest informcja o tym ile
 obiektow typu Prezent aktualnie istnieje.

 UWAGA!!!
 Do rozwiazania zadania nie wolno uzywac tablic ani wektorow. Uzycie
 niedozwolonej struktury oznacza 0 punktow.

 Pliku main.cpp nie wolno modyfikowac (oczywiście w trakcie pracy można sobie
 komentować fragmenty).

 CMakeLists.txt dolaczony do rozwiazania powinien tworzyc plik wykonywalny
 o nazwie CPPLab (nalezy kopiowac sobie CMakeLists.txt z poprzednich zajec).
 Program nalezy kompilowac z flagami -Wall -g.
 Prosze zadbac o dobre zarzadzanie pamiecia.

 Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
 ani żadnych innych materiałów (w tym własnych wcześniej
 przygotowanych plików)

 Rozwiązanie (archiwum zip) należy przesłać na UPeL do godziny 9:30.

 Przypominam, ze nie oceniam programow, ktore sie nie kompiluja.
 W przypadku Seg. Fault za output otrzymuje się 0 pkt.*/

#include <iostream>
#include "Prezent.h"
#include "Worek.h"

int main() {

  // UWAGA!!!
  // Do rozwiazania zadania nie wolno uzywac tablic ani wektorow. Uzycie
  // niedozwolonej struktury oznacza 0 punktow.
  // Rowniez nie nalezy korzystac z deklaracji przyjazni.
  const float wartoscCzapki = 100;
  Prezent czapka (wartoscCzapki);
  Prezent skarpety (35);
  skarpety.Wypisz();
  Prezent* wypasionaCzapka = new Prezent (200);
  Prezent szalik (55);

  skarpety.NapiszIleJestPrezentow();
  delete wypasionaCzapka;
  skarpety.NapiszIleJestPrezentow();

  Worek worekZPrezentami;

  worekZPrezentami.Wloz(skarpety);
  worekZPrezentami.Wloz(szalik);
  worekZPrezentami.Wloz(czapka);
  worekZPrezentami.Wloz(szalik);

  skarpety.NapiszIleJestPrezentow();

  worekZPrezentami.Wyciagnij().Wypisz();
  worekZPrezentami.Wyciagnij().Wypisz();
  std::cout<<"W polowie"<<std::endl;
  skarpety.NapiszIleJestPrezentow();
  worekZPrezentami.Wyciagnij().Wypisz();
  worekZPrezentami.Wyciagnij().Wypisz();
  worekZPrezentami.Wyciagnij();

  skarpety.NapiszIleJestPrezentow();
  
  return 0;
}
/* output:
Ten prezent kosztuje: 35
Aktualna liczba prezentow: 4
Aktualna liczba prezentow: 3
Aktualna liczba prezentow: 7
Ten prezent kosztuje: 55
Ten prezent kosztuje: 100
W polowie
Aktualna liczba prezentow: 5
Ten prezent kosztuje: 55
Ten prezent kosztuje: 35
Niestety, prezenty juz sie skonczyly.
Aktualna liczba prezentow: 3
*/
