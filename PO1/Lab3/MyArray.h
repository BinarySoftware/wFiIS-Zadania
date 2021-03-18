#pragma once

#include <iostream>

/** Klasa trzymająca tablice liczb calkowitych i definiujaca
 *  funkcje na  niej.
 */
class MyArray {
  public:

    /** Konstruktor nowego obiektu.
     * @param s - rozmiar tablicy.
     */
    MyArray(int s): 
      _size(s),
      tab(new int[s]){}
    ~MyArray();

    /** Konstruktor kopiujacy.
     */
    MyArray(const MyArray & a);

    /** Konstruktor przenoszacy
     */
    MyArray(MyArray && a);

    /** Przeladowany operator [] zwracajacy jeden element tablicy.
     * @param i - indeks elementu w tablicy.
     * @return wartosc.
     */
    int & operator[](int i);
    const int & operator[](int i) const;

    /** 
     * Wypisuje `a` do std:out 
     */
    friend std::ostream & operator<<(std::ostream & ostr, MyArray const & a) {
      ostr << "[";
      for (int i = 0; i < a._size-1; i++){
        ostr << a.tab[i] << ", ";
      }
      ostr << a.tab[a._size-1] << "]";
      return ostr;
    }

    /** 
     * Getter pola size.
     */
    int size(){
      return _size;
    }

    /** 
     * Getter kolejnej tablicy.
     */
    // MyArray getNext(){
    //   MyArray a2 = *this;
    //   if (_curr < sizeOfsize){
    //     a2._curr++;
    //   } else {
    //     a2._curr = 0;
    //   }
    //   return a2;
    // }

    /** 
     * Postinkrementacja kazdego elementu tablicy.
     */
    MyArray operator++(int);

    /** 
     * Predekrementacja kazdego elementu tablicy.
     */
    MyArray operator--();

    /** 
     * Operator przypisania.
     */
    MyArray & operator=(MyArray & a);

    /** 
     * dodanie kolejnej tablicy do obecnej.
     */
    // MyArray operator+=(MyArray &);

    /** Drukowanie tablicy
     */
    void print(std::string s);
  private:
    // int * _size; /** Rozmiar tablicy. */
    // int sizeOfsize;
    // int _curr; /** Ktora teraz tablica jest przegladana. */
    int _size;
    int * tab; /** Dynamicznie alokowana tabica */
};
