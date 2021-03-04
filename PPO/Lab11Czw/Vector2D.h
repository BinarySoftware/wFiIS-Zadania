#pragma once

#include <iostream>

static int count = 0;

class Vector2D{
	public:
		/**Funkcja tworząca obiekt ze zmiennych kartezjańskich
		@param x współrzędna x
		@param y współrzędna y
		@return utworzony obiekt
		*/
		static Vector2D fromCarthesian(double x, double y);

		/**Funkcja tworząca obiekt ze zmiennych biegunowych
		@param r promień
		@param phi kąt
		@return utworzony obiekt
		*/
		static Vector2D fromPolar(double r, double phi);

		/**Funkcja wypisująca wektor
		@param begin łańcuch zawierający nazwę wektora
		*/
		void print(std::string begin) const;

		/**Funkcja zwracająca liczbę wektorów
		*/
		static int number_vertices();

		/**Funkcja sumująca dwa wektory
		@param other drugi wektor do dodania
		@return obiekt będący sumą wektorów
		*/
		Vector2D add(const Vector2D &other) const;

		/**Funkcja licząca iloczyn skalarny
		@param other drugi obiekt do mnożenia
		@return wynik
		*/
		double dot(const Vector2D &other) const;

		/**Konstruktor kopiujący
		@param other obiekt do skopiowania
		*/
		Vector2D(const Vector2D &other);

		/**Konstruktor przenoszący
		@param other obiekt do skopiowania
		*/
		Vector2D(Vector2D &&other);

		/**Destruktor
		*/
		~Vector2D();
	private:
		double _x; ///< współrzędna x
		double _y; ///< współrzędna y

		/**Konstruktor
		@param x współrzędna x
		@param y współrzędna y
		*/
		Vector2D(double x, double y);
};