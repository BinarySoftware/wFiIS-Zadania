#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <functional>

/**
  * Abstrakcja na wektor intow, dodajaca przydatne funkcje.
  */
class List {
  private:
    std::vector<int> v; /** ww. lista */

  public:
    /** Dodaje element na koniec wektora.
      */
    void insert(int elem){ v.push_back(elem); }

    /** Drukuje liste na ekranie.
      */
    void print(std::string s="") const {
      std::cout << s << "[ ";
      for (int elem : v) {
        std::cout << elem << " ";
      }
      std::cout << "]" << std::endl;
    }

    /** Filtruje liste po funkcji pobierajacej element tej listy
      * ktora zwraca wartosc logiczna.
      */
    List filter(std::function<bool(int)> f){
      List newList;
      std::copy_if(v.begin(),
                   v.end(),
                   std::back_inserter(newList.v),
                   f);
      return newList;
    }

    /** Zwraca element listy na pozycji i.
      */
    int & operator[](int i){
      return v.at(i);
    }
};
