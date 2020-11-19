/*
 Prosze dopisac pliki *.h oraz *.cpp.
 
 Celem zadania jest przecwiczenie uzywania referencji, wskaznikow a takze zmuszenie do uzywania modyfikatora const.

 Bedziemy tworzyc strukture MyString opakowujaca zwykla tablice znakowa. 
 Dla tej struktury dodamy kilka pomocnych funkcji. Miedzy innymi join, swap is del.
 
 UWAGA: W zadaniu trzeba uzyc referncji do wskaznika a takze defaultowych wartosci.
 
 Ostateczny program powinien byc przyjazny dla programisty (miec
 czytelny i dobrze napisany kod, a takze dokumentacje).
 
 Pliku main.cpp nie wolno modyfikowac (oczywiście w trakcie pracy można sobie
 komentować fragmenty).

 CMakeLists.txt dolaczony do rozwiazania powinien tworzyc plik wykonywalny
 o nazwie Lab07. Program nalezy kompilowac z flagami -Wall -g.
 Prosze zadbac o dobre zarzadzanie pamiecia.

 Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
 ani żadnych innych materiałów (w tym własnych wcześniej
 przygotowanych plików)

 Rozwiązanie (archiwum zip) należy przesłać na UPeL do godziny 9:30.

 Przypominam, ze nie oceniam programow, ktore sie nie kompiluja.
 
 */

#include <iostream>
#include "MyString.h"
#include "MyString.h"

int main() {

  MyString s1;
  init(s1, "hello");
  std::cout << s1.str << std::endl;

  MyString s2;
  init(s2, "world");

  const MyString& r1 = s1;
  const MyString& r2 = s2;
  MyString s3 = join(r1, r2); // generujemy nowy napis sklejony z dwoch argumentow
  std::cout << s3.str << std::endl;

  std::cout << "before swapping: " << s1.str  << " " << s2.str << std::endl;
  swap(s1, s2);
  std::cout << "after swap: " << s1.str  << " " << s2.str << std::endl;
  MyString* s1ptr = &s1;
  MyString* s2ptr = &s2;
  std::cout << "before swapping ptr: " << s1ptr->str  << " " << s2ptr->str << std::endl;
  swap( s1ptr, s2ptr ); // przeladowana funkcja
  std::cout << "after ptr test: " << s1ptr->str  << " " << s2ptr->str << std::endl;
  std::cout << "originals: " << s1.str  << " " << s2.str << std::endl;

  del( s1, s1, s2, s3 ); // kasujemy wszystkie napisy, to powinna byc jedna funkcja, ktora moze odebrac od 1go do 5 argumentow (s1 jest celowo 2 razy!)
  del( s1 );
}
/* output:
hello
helloworld
before swapping: hello world
after swap: world hello
before swapping ptr: world hello
after ptr test: hello world
originals: world hello
deleting world
deleting hello
deleting helloworld
*/
