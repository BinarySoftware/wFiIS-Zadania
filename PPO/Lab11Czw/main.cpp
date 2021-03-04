/*
Celem zadania jest przećwiczenie konstruktorów,
a także funkcji i zmiennych statycznych.

Wektor można przedstawić np. we współrzędnych biegunowych lub kartezjańskich. Jednak
konstruktor z dwoma argumentami double byłby niejednoznaczny:
Vector2D(double x, double y);
Vector2D(double r, double phi); // żle!

Z tego powodu można użyć tzw. named constructor idiom, tj. stworzyć funkcje zwracające obiekt.
- fromCarthesian(double x, double y);
- fromPolar(double r, double phi);

Proszę zaimplementować klasę Vector2D, reprezentującą wektor ma on 2 współrzędne i metody:
   - add, wylicza sumę dwóch wektorów
   - dot, wylicza iloczyn skalarny dwóch wektorów
   - print - wypisuje wektor
   - zwracające obiekt Vector2D na podstawie współrzędnych
  Ponadto możliwe jest zliczanie obiektów klasy.

UWAGA:
- Wymagane utworzenie konstruktora przenoszącego oprócz kopiującego (za brak -1 pkt).
- Nalezy nie korzystać z deklaracji przyjazni.
- Nie trzeba definiować dwóch funkcji print (parametry domyślne).
- Przypominam, że iloczyn skalarny oblicza się ze wzoru x1*x2+y1*y2.
- Przeliczanie współrzędych biegunowych na kartezjańskie: [r*cos(α), r*sin(α)] M_PI to wartość liczby pi.

Pliku main.cpp nie wolno modyfikowac (oczywiście w trakcie pracy można sobie
komentować fragmenty).

CMakeLists.txt dolaczony do rozwiazania powinien tworzyc plik wykonywalny
o nazwie CPPLab (nalezy kopiowac sobie CMakeLists.txt z poprzednich zajec).
Prosze zadbac o dobre zarzadzanie pamiecia.

Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
ani żadnych innych materiałów (w tym własnych wcześniej
przygotowanych plików)

Rozwiązanie (archiwum zip) należy przesłać na UPeL do godziny 9:30.

Przypominam, ze nie oceniam programow, ktore sie nie kompiluja.
W przypadku Seg. Fault za output otrzymuje się 0 pkt.
*/

#include <iostream>
#include "Vector2D.h"

int main() {
	{
		Vector2D v1 = Vector2D::fromCarthesian(2., 3.);		// (x, y)
		const Vector2D v2 = Vector2D::fromPolar(4., 30.);	// (promień, kąt w stopniach)

		v1.print("v1: ");
		v2.print("v2: ");
		std::cout << "==== START: Number of Vector2Ds: " << Vector2D::number_vertices() << std::endl;

		double prod = v1.dot(v2);
		std::cout << "Dot product = " << prod << std::endl;
		
		const Vector2D v3 = v1.add(v2); 
		v3.print("v3: ");
		std::cout << v3.dot(v1) << ", " << v3.dot(v2) << std::endl;

		Vector2D v4 = v2;
		v4.print("v4: ");
		std::cout << "==== MIDDLE: Number of Vector2Ds: " << Vector2D::number_vertices() << std::endl;

		Vector2D v5 (std::move(v3.add(v1)));
		v5.print("v5: ");
	}
	std::cout << "==== END: Number of Vector2Ds: " << Vector2D::number_vertices() << std::endl;
}
/* output:

v1: (2, 3)
v2: (3.4641, 2)
==== START: Number of Vector2Ds: 2
Dot product = 12.9282
v3: (5.4641, 5)
25.9282, 28.9282
copying  (3.4641, 2)
v4: (3.4641, 2)
==== MIDDLE: Number of Vector2Ds: 4
moving  (7.4641, 8)
v5: (7.4641, 8)
==== END: Number of Vector2Ds: 0
*/
