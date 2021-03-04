/*Celem zadania jest porownanie implementacji z uzyciem klas i struktur.
 Zadanie jest wariantem poprzednego.

 Nalezy stworzyc  klase MyString opakowujaca zwykla tablice znakowa. 
 Dla tej klasy dodamy kilka pomocnych metod. 

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
#include "MyString.h"

int main() {
  /*UWAGA: W zadaniu nie mozna uzyc klasy std::string. Tj. musi byc to zrobione na char*.
  UWAGA: W klasie MyString moze miec wiecej przydatnych method niz te, ktore sa uzyte w przykladzie.
  */
    
  MyString s1("witaj");
  s1.print();

  const MyString s2 = MyString::create("swiecie");
  
  s1.join(s2); // zmieniamy wnetrze klasy
  s1.print();

  s1.replace("jest");

  MyString s3("ciekawie");
  std::cout << "przed zamiana: " << std::endl;
  s1.print();
  s3.print();
  swap(s1, s3);//zamieniamy tylko char*, a nie cale obiekty
  std::cout << "po zamianie: " << std::endl;
  s1.print();
  s3.print();
  

}
/* output:

ID: 1str: witaj
ID: 1str: witajswiecie
przed zamiana: 
ID: 1str: jest
ID: 3str: ciekawie
po zamianie: 
ID: 1str: ciekawie
ID: 3str: jest
- deleting jest
- deleting swiecie
- deleting ciekawie
   
*/
