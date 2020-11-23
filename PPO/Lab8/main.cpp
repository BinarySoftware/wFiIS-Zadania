/*
 Celem zadania jest porownanie implementacji z uzyciem klas i struktur.
 Zadanie jest wariantem poprzednego.

 Nalezy stworzyc  klase MyString opakowujaca zwykla tablice znakowa. 
 Dla tej klasy dodamy kilka pomocnych metod. Miedzy innymi join, swap is del.

 Dodatkowo nalezy zaimplementowac klase MyStringHelper.
 
 
 Ostateczny program powinien byc przyjazny dla programisty (miec
 czytelny i dobrze napisany kod, a takze dokumentacje).
 
 Pliku main.cpp nie wolno modyfikowac (oczywiście w trakcie pracy można sobie
 komentować fragmenty).

 CMakeLists.txt dolaczony do rozwiazania powinien tworzyc plik wykonywalny
 o nazwie CPPLab (nalezy kopiowac sobie CMakeLists.txt na kolejnych zajeciach).
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
#include "MyStringHelper.h"
#include "MyString.h"
#include "MyString.h"
#include "MyStringHelper.h"

int main() {
  /*UWAGA: W zadaniu nie mozna uzyc klasy std::string. Tj. musi byc to zrobione na char*.
  UWAGA: W klasie MyString moze miec wiecej przydatnych method niz te, ktore sa uzyte w przykladzie.
  UWAGA: nie mozna korzystac z klas zaprzyjaznionych (friend)
  */

  MyString s1;
  s1.set_string("witaj");
  std::cout << s1.str() << std::endl;

  MyString s2;
  s2.set_string("swiecie");
  
  s1.join(s2); // zmieniamy wnetrze klasy
  std::cout << s1.str() << std::endl;

  s1.replace("jest");

  MyString s3;
  s3.set_string("ciekawie");
  std::cout << "przed zamiana: " << s1.str()  << " " << s3.str() << std::endl;

  s1.swap(s3);//tutaj powinno byc zmienione tylko wnetrze klas (zmienna char*)
  std::cout << "po zamianie: " << s1.str()  << " " << s3.str() << std::endl;

  
  MyStringHelper helper;
  helper.replace(s1, "bardzo");
  std::cout << "przed zamiana: " << s1.str()  << " " << s3.str() << std::endl;

  swap(s1, s3);//tutaj powinno byc zmienione tylko wnetrze klas (zmienna char*) - powinno to byc zaimplementowane w MyStringHelper.h/MyStringHelper.cpp
  std::cout << "po zamianie: " << s1.str()  << " " << s3.str() << std::endl;

  s1.clear_string();
  s2.clear_string();
  s3.clear_string();

}
/* output:
witaj
witajswiecie
przed zamiana: jest ciekawie
po zamianie: ciekawie jest
przed zamiana: bardzo jest
po zamianie: jest bardzo
- deleting jest
- deleting swiecie
- deleting bardzo 
*/
