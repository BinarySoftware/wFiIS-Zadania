/*
Prosze napisac klase Worek, ktora dziala jak lista. W liscie beda
przechowywane obiekty typu Prezent, ktore zawieraja informacje o
cenie. Elementy z listy mozna usuwac.
 
UWAGA!!!
Do rozwiazania zadania nie wolno uzywac tablic ani wektorow. Uzycie
niedozwolonej struktury oznacza 0 punktow.

Ostateczny program powinien byc przyjazny dla programisty (miec
czytelny i dobrze napisany kod, a takze dokumentacje).

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
W przypadku Seg. Fault za output otrzymuje się 0 pkt.
*/

#include <iostream>
#include "Prezent.h"
#include "Worek.h"

void UkradnijPrezenty (Worek worekZPrezentami)
{
  std::cout<<"Kradne prezenty 3 i 1\n";

  worekZPrezentami.UsunPrezentNumer(3);
  worekZPrezentami.UsunPrezentNumer(1);

  worekZPrezentami.WypiszZawartosc();
}

int main(){
  // UWAGA!!!
  // Do rozwiazania zadania nie wolno uzywac tablic ani wektorow. Uzycie
  // niedozwolonej struktury oznacza 0 punktow.
    
  const float wartoscCzapki = 100;
  Prezent czapka (wartoscCzapki);
  Prezent skarpety (35);
  skarpety.Wypisz();
  Prezent wypasionaCzapka (200);
  Prezent szalik (55);

  Worek worekZPrezentami;
  worekZPrezentami.Wloz(skarpety);
  worekZPrezentami.Wloz(szalik);
  worekZPrezentami.Wloz(czapka);
  worekZPrezentami.Wloz(szalik);
  worekZPrezentami.Wloz(wypasionaCzapka);

  worekZPrezentami.WypiszZawartosc();

  worekZPrezentami.UsunPrezentNumer(5);
  worekZPrezentami.UsunPrezentNumer(2);
  worekZPrezentami.WypiszZawartosc();

  UkradnijPrezenty (worekZPrezentami);
  
  std::cout<<"Na szczescie nic nie zginelo.\n";

  worekZPrezentami.WypiszZawartosc();
  
  return 0;
}
/* output:
Prezent o wartosci: 35
=== Zawartosc worka ===
1. Prezent o wartosci: 35
2. Prezent o wartosci: 55
3. Prezent o wartosci: 100
4. Prezent o wartosci: 55
5. Prezent o wartosci: 200
=== Zawartosc worka ===
1. Prezent o wartosci: 35
2. Prezent o wartosci: 100
3. Prezent o wartosci: 55
Kradne prezenty 3 i 1
=== Zawartosc worka ===
1. Prezent o wartosci: 100
Na szczescie nic nie zginelo.
=== Zawartosc worka ===
1. Prezent o wartosci: 35
2. Prezent o wartosci: 100
3. Prezent o wartosci: 55
*/
