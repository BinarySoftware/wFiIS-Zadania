// Prosze dopisac pliki *.h oraz *.cpp.

// Celem zadania jest implementacja listy dwukierunkowej.
// Każdy element listy dwukierunkowej zawiera dane oraz wskaźniki na kolejny oraz poprzedni element
// listy. Dla ostatniego elementu listy wskaźnik na następny element jest ustawiony na NULL (nullptr).
// Dla pierwszego elementu listy wskaźnik na poprzedni element jest ustawiony na NULL (nullptr).

// Zadanie najprosciej jest rozwiazac tworzac dwie struktury:
// node (wezel) - odpowiadajaca jednemu elementowi listy. Powinna zawierac dane oraz
// wskazniki do poprzedniego oraz nastepnego elementu.
// struktura glowna (List) - zawierajaca adres początku listy czyli pierwszego elementu (head).
// Metoda prepare ustawia wskaznik head na NULL (nullptr).

// Niektóre z funkcji nie zmieniają listy i z tego powodu powinny odbierać
// stały wskaźnik do struktury List.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod, a takze dokumentacje).

// Pliku main.cpp nie wolno modyfikowac (oczywiście w trakcie pracy można sobie
// komentować fragmenty).

// CMakeLists.txt dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Lab05. Program nalezy kompilowac z flagami -Wall -g.
// Prosze zadbac o dobre zarzadzanie pamiecia.

// Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
// ani żadnych innych materiałów (w tym własnych wcześniej
// przygotowanych plików)

// Rozwiązanie (archiwum zip) należy przesłać na UPeL do godziny 9:30.

// Przypominam, ze nie oceniam programow, ktore sie nie kompiluja.
//


// Powodzenia!

#include <iostream>
#include <cstring>
#include "lab05.h"
#include "lab05.h"

using namespace std;
int main() {
  List testList;
  cout << "Przygotowuje liste do wstawiania danych." << endl;
  prepare(&testList);
  const List* lptr = &testList;
  char buffer[100];
  
  cout << "Kopiuje nazwe..." << endl;
  strcpy(buffer, "Jakaś");
  push_back(&testList, buffer);
  
  strcpy(buffer, "lista");
  push_back(&testList, buffer);
  
  strcpy(buffer, "dwukierunkowa.");
  push_back(&testList, buffer);
    
  strcpy(buffer, "!!!");
  push_front(&testList, buffer);
    
  strcpy(buffer, "<<");
  push_front(&testList, buffer);
  
  cout << "Elementy dodane" << endl;
  std::cout << "empty() " << empty(lptr) << std::endl;
  std::cout << lptr->head->data << std::endl;
  std::cout << lptr->head->next->data << std::endl;
  std::cout << lptr->head->next->previous->data << std::endl;

  cout << "Wypisuje cala liste:" << endl;
  dump(lptr);
  std::cout << "\n";
   
  clear(&testList);
    
  std::cout << "empty() " << empty(lptr) << std::endl;
}

// Output:
/*
Przygotowuje liste do wstawiania danych.
Kopiuje nazwe...
Elementy dodane
empty() 0
<<
!!!
<<
Wypisuje cala liste:
<< !!! Jakaś lista dwukierunkowa.
empty() 1
*/
