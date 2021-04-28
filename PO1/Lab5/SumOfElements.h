#pragma once
#include "Operation.h"

/** Klasa sumujaca elementy. */
class SumOfElements : public Operation {
  public:
    /** Konstruktor główny. */
    SumOfElements(double * l, int n): list(l), size(n) {};

    /** redefinicja metody print() */
    void print() const override {
      for (int i = 0; i < size-1;  i++) { std::cout << list[i] << " + "; }
      std::cout << list[size-1];
    }

    /** redefinicja metody eval() */
    double eval() const override {
      double temp = 0;
      for (int i = 0; i < size;  i++) { temp += list[i]; }
      return temp;
    }
  private:
    double * list; /**< Lista przechowujaca dane wejsciowe. */
    int size; /**< rozmiar listy. */
};