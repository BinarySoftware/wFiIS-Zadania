#pragma once
#include "Operation.h"

/** Klasa dzielaca. */
class Division : public Operation {
  public:
    /** Konstruktor główny. */
    Division(int a, double b): dzielna(a), dzielnik(b) {}

    /** redefinicja metody print() */
    void print() const override {
      std::cout << dzielna << " / " << dzielnik;
    }

    /** redefinicja metody eval() */
    double eval() const override {
      return dzielna/dzielnik;
    }
  private:
    double dzielna; /**< Dzielna w dzialaniu dzielenia */
    double dzielnik; /**< Dzielnik w dzialaniu dzielenia */
};