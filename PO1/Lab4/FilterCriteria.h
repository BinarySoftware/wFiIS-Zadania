#pragma once
#include <iostream>
#include <vector>
#include <functional>

/** Lista kryteriow filtrujacych.
  */
class FilterCriteria {
  private:
    std::vector<std::function<bool(int)>> v; /** ww. wektor */
    
  public:
   /** Dodaje element na koniec wektora.
     */
    void add(std::function<bool(int)> f){ v.push_back(f); }

   /** Zwraca rozmiar wektora
     */
    int size(){ return v.size(); }

   /** Zwraca element wektora na pozycji i.
     */
    std::function<bool(int)> get(int i){ return v.at(i); };
};
