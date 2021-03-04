/*Celem zadania jest porownanie implementacji z uzyciem klas i struktur.
 Zadanie jest wariantem poprzednego.

 Nalezy stworzyc  klase MyString opakowujaca zwykla tablice znakowa.
 Dodatkowo nalezy przeciazyc  operatory: +,=,==,*,<<.


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

 Rozwiązanie (archiwum zip) należy przesłać na UPeL do godziny 9:30
 (po 9:30 nie bedzie mozliwosci doslania rozwiazania)

 Przypominam, ze nie oceniam programow, ktore sie nie kompiluja.
 W przypadku Seg. Fault za output otrzymuje się 0 pkt.
 */

#include <iostream>
#include "MyString.h"

int main() {
  /*UWAGA: W zadaniu nie mozna uzyc klasy std::string, tj. musi byc to zrobione na char*.
  */
    
  MyString s1("witaj");
  MyString s2("swiecie");
  std::cout << s1 << "\t" << s2 << std::endl;
  
  
  MyString s3 = s1+s2;
  std::cout << s1 << "\t" << s2 << "\t" << s3 << std::endl;
  s2 = "!!!";
  std::cout << s1 << "\t" << s2 << "\t" << s3 << std::endl;

  MyString s4 = 3 * s2;
  std::cout << s4 << std::endl;

  s1*3;
  std::cout << s1 << std::endl;
  3*s1;
  std::cout << s1 << std::endl;
  
  std::cout << (s2 == "!!!" ? "==" : "!=") << std::endl;

  std::cout << (s2 == "!!!aaa" ? "==" : "!=") << std::endl;

  const MyString s5(s3);
  std::cout << "s5: " << s5 << "\t s3: " << s3 << std::endl;

  const MyString s6 = std::move(s3);
  std::cout << "s6: " << s6 << std::endl;
}
/* output
witaj   swiecie
witaj   swiecie witajswiecie
witaj   !!! witajswiecie
!!!!!!!!!
witajwitajwitaj
witajwitajwitaj
==
!=
s5: witajswiecie     s3: witajswiecie
s6: witajswiecie
*/
