// Prosze dopisac pliki *.h oraz *.cpp.

// Proszę napisać funkcje wykonujące na liczbach zapisanych binarnie.
// operacje:
// 1) sumowania (add_up)    np. 1+0=1, 1+1=10
// 2) koniunkcja (bit_and)    np. 1&1=1, 1&0=0
// 3) alternatywa wykluczająca (bit_xor)    np. 1^1=0, 1^0=1
// 4) zamiana na system dziesiętny

// Uwaga:
// - proszę wykorzystać tablicę o stałym rozmiarze np. 32
//  i przechowywać informację o "długości" liczby (liczbie bitów).
//  Nadmiarowe bity można wypełnić zerami (można, ale nie trzeba)
// - można też użyć std::vector (jeśli ktoś zna i bardzo chce)
// - nie trzeba sprawdzać czy długości liczby i maski są zgodne
// - proszę zadbać o nie wychodzenie poza tablicę

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod, a takze dokumentacje).

// Pliku main.cpp nie wolno modyfikowac (oczywiście w trakcie pracy można sobie
// komentować fragmenty).

// CMakeLists.txt dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Lab06. Program nalezy kompilowac z flagami -Wall -g.
// Prosze zadbac o dobre zarzadzanie pamiecia.

// Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
// ani żadnych innych materiałów (w tym własnych wcześniej
// przygotowanych plików)

// Rozwiązanie (archiwum zip) należy przesłać na UPeL do godziny 9:30.

// Przypominam, ze nie oceniam programow, ktore sie nie kompiluja.
//


// Powodzenia!

#include "Lab06.h"
#include "Lab06.h"
#include <iostream>

int main (){
	int data1[] = {1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1};
	int data2[] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 1};

	Bits bits1;
	set(&bits1, data1, sizeof(data1)/sizeof(data1[0]) );
	Bits bits2;
	set(&bits2, data2, sizeof(data2)/sizeof(data2[0]) );
	print(&bits1);
	std::cout << "  ";
	print(&bits2);
 
	const Bits bits3 = add_up(&bits1, &bits2);

	std::cout << "summed: " << std::endl;
	print(&bits3);
	
	int mask_data[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1};
	Bits mask;
	set(&mask, mask_data, sizeof(mask_data)/sizeof(mask_data[0]) );

    function masks[] = {bit_and, bit_xor};
    const int numberOfMasks = sizeof(masks)/sizeof(function);
    const char* maskName[] = {"and", "xor"};

    for(int i = 0; i < numberOfMasks;i++){
        doOperation(masks[i],&bits1,&mask);
        std::cout << "after " << maskName[i] << ": " << std::endl;
        print(&bits1);
    }
   
	const Bits bits4 = add_up(&bits1, &bits2);
	std::cout << "summed again: " << std::endl << " ";
	print(&bits4);

	std::cout << to_decimal(&bits1) << " + " << to_decimal(&bits2) << " = ";
	std::cout << to_decimal(&bits4) << std::endl;
}
/*
Wynik:
110011101111

  1010101011

summed:
111110011010

after and:
110010101101

after xor:
  1100010000

summed again:
 10110111011

784 + 683 = 1467


*/
