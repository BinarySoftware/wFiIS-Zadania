#pragma once
#include<iostream>

/** ComplexNumber
Przechowuje liczby zlozone i definiuje podstawowe operatory na nich.
*/
class ComplexNumber {
  public:
    /**
    Konstruktor główny.
    @param r - czesc rzeczywista
    @param im - czesc urojona
    */
    explicit ComplexNumber(double r, double im = 0){
      this->r  = r;
      this->im = im;
    }

    /**
    Cast Complex do double.
    */
    operator double() {
      return r;
    }

    /**
    Wysyla Complex do wyswietlenia w ostream.
    @param ostr - output stream.
    @param c - liczba.
    */
    friend std::ostream & operator<<(std::ostream & ostr, ComplexNumber const & c) {
      ostr << c.r << " + " << c.im <<"i";
      return ostr;
    }

    /**
    Dodaje 2 liczby do siebie.
    @param c1 - liczba 1.
    @param c2 - liczba 2.
    */
    friend ComplexNumber operator+(const ComplexNumber c1, const ComplexNumber c2) {
      return ComplexNumber(c1.r + c2.r, c1.im + c2.im);
    }

    /**
    Odejmuje 2 liczby od siebie.
    @param c1 - liczba 1.
    @param c2 - liczba 2.
    */
    friend ComplexNumber operator-(const ComplexNumber c1, const ComplexNumber c2) {
      return ComplexNumber(c1.r - c2.r, c1.im - c2.im);
    }

    /**
    Dodaje inta do zespolonej.
    @param i - liczba 1.
    @param c - liczba 2.
    */
    friend ComplexNumber operator+(int i, const ComplexNumber c2) {
      return ComplexNumber(i + c2.r, c2.im);
    }

    /**
    Mnozy 2 liczby przez siebie.
    @param c1 - liczba 1.
    @param c2 - liczba 2.
    */
    friend ComplexNumber operator*(const ComplexNumber c1, const ComplexNumber c2) {
      return ComplexNumber(c1.r*c2.r - c1.im*c2.im, c1.r*c2.im + c1.im*c2.r);
    }

    /**
    Sprawdza ktora liczba jest wieksza.
    @param c1 - liczba 1.
    @param c2 - liczba 2.
    */
    friend bool operator>(const ComplexNumber c1, const ComplexNumber c2) {
      double ls1 = c1.r*c1.r + c1.im*c1.im;
      double ls2 = c2.r*c2.r + c2.im*c2.im;
      return ls1 > ls2;
    }

    /**
    Odwołuje się albo do r albo im jesli i = 0 lub 1 (dla wygody 1 -> Kazda liczba != 0).
    */
    double & operator[](int i);

    /**
    Dodaje +1 do r. (preinkrementajca)
    @param c - liczba .
    */
    ComplexNumber operator++();

    /**
    Dodaje +1 do r. (postinkrementajca)
    @param c - liczba .
    */
    ComplexNumber operator++(int);

    /**
    Mnozy elementy liczby przez inta.
    @param c - liczba .
    @param i - mnoznik.
    */
    void operator*=(int i);

  private:
    double r; /** przechowuje czesc rzeczywista. */
    double im; /** przechowuje czesc urojona. */
};