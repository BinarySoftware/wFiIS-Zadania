#pragma once
#include <vector>
#include <string>

/**
 * Klasa przechowujaca wydatki z danego dnia tygodnia.
 */
class Expense {
  public:
    Expense(std::string d, std::vector<double> e): day(d), exp(e) {}
 
    /**
    * Wypisuje wydatki na ekran.
    */
    void print() const;

    /**
    * Zwraca srednia wydatkow.
    */
    double mean() const;

    /**
    * Funkcja pomocnicza - zwraca i-ty wydatek.
    */
    double at(int i) const;

    /**
    * Funkcja pomocnicza - zwraca ilosc wydatkow.
    */
    unsigned int size() const;
  private:
    std::string day;         /// Dzien tygodnia.
    std::vector<double> exp; /// Wektor wydatkow.
};
