#pragma once
#include "Animals.h"
#include <vector>
#include <memory>
#include <string>

/** Klasa Meadow przechowuje wszystkie zwierzeta na polu.
 */
class Meadow {
  public:

    /** Dodaje nowe zwierze do listy zwierzat na polu.
    */
    void add(std::unique_ptr<Animal> a);

    /** Wypisuje wszystkie zwierzeta na ekran.
    */
    void print(const std::string & s);

    /** Zlicza ilosc wystapien imion w stadzie.
    */
    void countNames();

    /** Zwraca stado owiec ze stada zwierzat.
    */
    std::vector<Sheep *> getSheepHerd();
  private:
    std::vector<std::unique_ptr<Animal>> allAnimals; /// Przechowuje wszystkie zwierzeta na polu.
};