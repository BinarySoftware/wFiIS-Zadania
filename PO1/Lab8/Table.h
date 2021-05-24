#pragma once
#include "Expense.h"

/**
* Klasa przechowujaca wektor wydatkow.
*/
class Table {
  public:
    /**
    * Dodaje nowy wydatek do wektora wydatkow.
    * @param e - Wydatek klasy Expense.
    */
    void operator +=(const Expense & e);

    /**
    * Wypisuje wszystkie wydatki na ekran.
    */
    void print() const;

    /**
    * Sortuje wydatki po kolumnie.
    * @param i - kolumna do sortowania po.
    */
    Table & sort(unsigned int i);

    /**
    * Sortuje wydatki po ich sredniej.
    */
    Table & sortByMean();
  private:
  std::vector<Expense> expenses; /// Wszystkie wydatki.
};
