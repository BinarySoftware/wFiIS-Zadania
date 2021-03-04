#pragma once
#include <iostream>


int nwd(int m, int n){
  int oldm, oldn;
    while( m % n != 0 ){
        oldm = m;
        oldn = n;
      m = oldn;
      n = oldm % oldn;
  }
  return n;
}


/**
 * Fraction.
 *
 * Klasa przechowująca ułamek w formie licznika z mianownikiem.
 */
class Fraction {
  public:
    /** Konstruktor z 1 pola.
     * @param l - nowy licznik.
     */
    Fraction(int l){
      _l = l;
      _m = 1;
    }

    /** Konstruktor z 2 pol.
     * @param l - nowy licznik.
     * @param m - nowy mianownik.
     */
    Fraction(int l, int m){
      _l = l;
      _m = m;

      if (m < 0) {
        _l *= -1;
        _m *= -1;
      }

      int d = simplify(_l,_m);
      _l /= d;
      _m /= d;
    }

    /** Konstruktor kopiujacy.
     * @param f - fraction.
     */
    Fraction(const Fraction & f) {
      _l = f._l;
      _m = f._m;
    }

    /** Konstruktor przenoszacy.
     * @param f - fraction.
     */
    Fraction(Fraction & f){
      _l = std::move(f._l);
      _m = std::move(f._m);
    }

    /** Operator << dla ostream-u.
     * Pozwala na proste printowanie ulamka.
     * @param ostr - output stream.
     * @param f - fraction. 
     * @return - ostream.
     */
    friend std::ostream & operator<<(std::ostream & ostr, Fraction const & f){
       ostr << f._l;
       if (f._m != 1) {
         ostr << "\\" << f._m;
       }
       return ostr;
    }

    /** Wylicza NWD aby uproscic ulamek.
     * @param l - nowy licznik.
     * @param m - nowy mianownik.
     */
    int simplify(int l, int m){
      return nwd(m,l);
    }

    /** Konwersja na double.
     */
    operator double() const {
      return (double)_l / (double)_m;
    }
  private:
    int _l; /** Licznik */
    int _m; /** Mianownik */
};