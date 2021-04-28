#pragma once
#include "Operation.h"
#include <cmath>

/** Klasa potegujaca. */
class Exponentiation : public Operation {
  public:
    /** Konstruktor główny. */
    Exponentiation(int a, double x): podstawa(a), wykladnik(x) {};

    /** redefinicja metody print() */
    void print() const override {
      std::cout << podstawa << " ^ " << wykladnik;
    }

    /** redefinicja metody eval() */
    double eval() const override {
      return pow(podstawa, wykladnik);
    }
  private:
    double podstawa; /** podstawa potegowania. */
    double wykladnik; /** wykladnik potegowania. */
};