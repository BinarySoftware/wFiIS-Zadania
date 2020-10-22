// Prosze dopisac pliki *.h oraz *.cpp., ktore zawierajace funkcje tworzace i operujace na
//ciagach Fibonacciego (ciag liczb naturalnych, gdzie F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2)).
//Nalezy utworzyc tablice zawierajaca ciagi Fibonacciego, gdzie:
//sequencesList - tablica zawierajaca ciagi Fibonacciego
//sequencesLenght - tablica zawierajaca informacje o ilosci wyrazow w danym ciagu
//numberOfSequences - aktualna ilosc ciagow
//Dodatkowo nalezy zaimplementowac funkcje wypisujaca ciagi, a takze funkcje usuwajaca ciag o danym ID.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod, a takze dokumentacje).

// Pliku main.cpp, nie wolno modyfikowac.

// CMakeLists.txt dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Lab03. Program nalezy kompilowac z flagami -Wall -g.
// Prosze zadbac o dobre zarzadzanie pamiecia.

// Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
// ani żadnych innych materiałów (w tym własnych wcześniej
// przygotowanych plików)

//Rozwiązanie (archiwum zip) należy przesłać na UPeL do godziny 9:30.

//Powodzenia!

#include <iostream>
#include "lab03.h"

using namespace std;
int main() {
  const int n = -5;
  cout << "Liczba " << n << endl;
  const int abs_n = abs(n);
  cout << "Jej wartosc bezwzgledna wynosi " <<  abs_n << endl;

  const int* sequence = initFibonacci(abs_n);
  cout << "Ciag Fibonacciego dla |n| = " << abs_n << ": ";
  print(sequence,abs_n);
  deleteSequence(sequence);

  int numberOfSequences = 0;
  int** sequencesList = NULL;
  int* sequencesLenght = NULL;

  addSequence(&numberOfSequences, &sequencesList, &sequencesLenght, -5);
  addSequence(&numberOfSequences, &sequencesList, &sequencesLenght, 4);
  addSequence(&numberOfSequences, &sequencesList, &sequencesLenght, 6);
  

  cout << "Wypisuje wszystkie ciagi: " << endl;
  printAllSequences(sequencesList,sequencesLenght,numberOfSequences);

  removeSequence(&numberOfSequences, &sequencesList, &sequencesLenght, 1);
  cout << "Wypisuje wszystkie ciagi:  " << endl;
  printAllSequences(sequencesList,sequencesLenght,numberOfSequences);

  
  deleteSequences(&numberOfSequences, &sequencesList, &sequencesLenght);

}
//Output:
//Liczba -5
//Jej wartosc bezwzgledna wynosi 5
//Ciag Fibonacciego dla |n| = 5: (0, 1, 1, 2, 3, 5)
//Wypisuje wszystkie ciagi:
//Ciag nr 0: (0, 1, 1, 2, 3, 5)
//Ciag nr 1: (0, 1, 1, 2, 3)
//Ciag nr 2: (0, 1, 1, 2, 3, 5, 8)
//Wypisuje wszystkie ciagi:
//Ciag nr 0: (0, 1, 1, 2, 3, 5)
//Ciag nr 1: (0, 1, 1, 2, 3, 5, 8)

