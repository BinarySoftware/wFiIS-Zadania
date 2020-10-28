// Prosze dopisac pliki *.h oraz *.cpp.

// Prosze napisac strukture MapPoint, ktora reprezentuje punkt na
// mapie skladajacy sie z nazwy, dlugosci (longitude) i szerokosci
// (latitude) geograficznej.

// Funkcja inTheMiddle powinna tworzyc nowy punkt na mapie o zadanej
// nazwie i polozeniu, ktore jest srednia arytmetyczna z polozen
// podanych punktow czyli x = (x_1 + x_2)/2

// Funkcja distanceMag powinna obliczac odleglosc miedzy dwoma punktami
// jako sqrt(latitude^2+longitude^2), sqrt dostepne w bibliotece <cmath>.

// Funkcja closestFrom pobiera 3 argumenty. Pierwszy argument jest
// punktem referencyjnym. Z dwoch kolejnych wybiera ten, ktory jest
// najblizej punktu referencyjnego.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod, a takze dokumentacje).

// Pliku main.cpp nie wolno modyfikowac (oczywiście w trakcie pracy można sobie
// komentować fragmenty).

// CMakeLists.txt dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Lab04. Program nalezy kompilowac z flagami -Wall -g.
// Prosze zadbac o dobre zarzadzanie pamiecia.

// Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
// ani żadnych innych materiałów (w tym własnych wcześniej
// przygotowanych plików)

// Rozwiązanie (archiwum zip) należy przesłać na UPeL do godziny 9:30.

// Przypominam, ze nie oceniam programow, ktore sie nie kompiluja.

// Powodzenia!

#include <iostream>
#include "lab04.h"
#include "lab04.h"

int main() {
  const double longitude = 19.938333;
  const double latitude = 50.061389;
  MapPoint* krk     = construct("Krakow", latitude, longitude);
  print(krk);
  MapPoint* nyc     = construct("NYC", 40.7127, -74.0059 );
  print(nyc);
  MapPoint* porto   = construct("Porto", 41.162142, -8.621953 );
  print(porto);
  MapPoint* irkutsk = construct("Irkutsk",  52.283333, 104.283333);
  MapPoint siberiaCapital = *irkutsk;
  print(&siberiaCapital);

  MapDist d = distance(nyc, *porto);
  std::cout << d.latitude << " " << d.longitude  << " " << distanceMag(d) << std::endl;

  MapPoint mp = inTheMiddle(krk, &siberiaCapital, "Somewhere in Russia");
  print(&mp);

  MapPoint cl = closestFrom(krk, porto, &siberiaCapital);
  std::cout << name(cl) << std::endl;

  const double moveLatitude = 5.;
  const double moveLongitude = 10.;
  move(&krk, moveLatitude, moveLongitude);
  print(krk);
    
  clear(irkutsk);
    
  MapPoint* tab[] = { krk, nyc, porto };
  int rozmiar = sizeof(tab)/sizeof(MapPoint*);
  clear(tab,rozmiar);
  

}
//Output:
/*
 Position of Krakow. Latitude: 50.0614. Longitude: 19.9383
 Position of NYC. Latitude: 40.7127. Longitude: -74.0059
 Position of Porto. Latitude: 41.1621. Longitude: -8.62195
 Position of Irkutsk. Latitude: 52.2833. Longitude: 104.283
 -0.449444 -65.3839 65.3855
 Position of Somewhere in Russia. Latitude: 51.1724. Longitude: 62.1108
 Porto
 Position of Krakow. Latitude: 55.0614. Longitude: 29.9383
 */


