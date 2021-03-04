// Prosze dopisac pliki *.h oraz *.cpp.

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klase MapPoint, ktora reprezentuje punkt na
// mapie skladajacy sie z dlugosci (longitude) i szerokosci
// (latitude) geograficznej bez oznaczania polkol.

// Funkcja print klasy MapPoint wypisuje na ekran, ze jest to punkt i
// podaje jego wspolrzedne w nawiasach okraglych.

// Metoda set_coordinates ustawia szerokosc i dlugosc geograficzna
// punktu na podstawie argumentow, ktore przyjmuje.

// Funkcja distance w klasie MapPoint zwraca obiekt typu MapDistance,
// ktory przechowuje informacje o roznicy pomiedzy dlugosciami
// geograficznymi dwoch punktow oraz roznicy pomiedzy szerokosciami
// geograficznymi tych samych punktow.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod, a takze dokumentacje).

// Pliku main.cpp nie wolno modyfikowac (oczywiście w trakcie pracy można sobie
// komentować fragmenty).

// CMakeLists.txt dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie CPPLab (nalezy kopiowac sobie CMakeLists.txt na kolejnych zajeciach).
// Program nalezy kompilowac z flagami -Wall -g.
// Prosze zadbac o dobre zarzadzanie pamiecia.

// Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
// ani żadnych innych materiałów (w tym własnych wcześniej
// przygotowanych plików)

// Rozwiązanie (archiwum zip) należy przesłać na UPeL do godziny 9:30.

// Przypominam, ze nie oceniam programow, ktore sie nie kompiluja.
// W przypadku Seg. Fault za output otrzymuje się 0 pkt.

// Powodzenia!


#include <iostream>
#include "MapDistance.h"
#include "MapPoint.h"
#include "MapPoint.h"
#include "MapDistance.h"

int main() {
  using std::cout;
  using std::endl;

  cout<<"========== KRK =========="<<endl;
  MapPoint krk;
  krk.set_coordinates(19.938333, 50.061389);
  krk.print();

  cout<<"========== NYC =========="<<endl;
  const double nyc_latitude = 40.7127;
  const double nyc_longitude = -74.0059;
  MapPoint nyc;
  nyc.set_coordinates (nyc_latitude, nyc_longitude);
  nyc.print();

  cout<<"========== PORTO & IRKUTSK =========="<<endl;
  MapPoint porto;
  porto.set_coordinates(41.162142, -8.621953);
  porto.print();
  MapPoint irkutsk;
  irkutsk.set_coordinates(52.283333, 104.283333);
  irkutsk.print();

  cout<<"========== DISTANCE =========="<<endl;
  MapDistance nyc_porto = nyc.distance(porto);
  nyc_porto.print();

  cout<<"========== SOMEWHERE =========="<<endl;
  MapPoint somewhere = krk.half_way_to(nyc);
  somewhere.print();


  return 0;
}
/* Output:
========== KRK ==========
Point: (19.9383, 50.0614)
========== NYC ==========
Point: (40.7127, -74.0059)
========== PORTO & IRKUTSK ==========
Point: (41.1621, -8.62195)
Point: (52.2833, 104.283)
========== DISTANCE ==========
Distance: (0.449444, 65.3839)
========== SOMEWHERE ==========
Point: (30.3255, -11.9723)
*/
