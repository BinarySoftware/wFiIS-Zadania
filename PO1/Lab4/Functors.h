#pragma once

/** Pozwala sprawdzic czy jedna liczba jest podzielna przez druga.
  */
class DivisibleBy {
  private:
    int byValue; /** dzielnik */

  public:
    /** konstruktor */
    DivisibleBy(int n): byValue(n) {}

    /** Shadowing operatora (), powoduje ze klasa zachowuje sie
      * jak funkcja, jest funktorem. 
      * pobiera druga liczbe do porownania.
      */
    bool operator() (int what) const {
      return (what % byValue == 0);
    }
};

/** Pozwala sprawdzic czy jedna liczba jest wieksza od drugiej.
  */
class GreaterThan {
  private:
    int thanValue; /** wartosc porownywana */

  public:
    /** konstruktor */
    GreaterThan(int n): thanValue(n) {}

    /** Shadowing operatora (), powoduje ze klasa zachowuje sie
      * jak funkcja, jest funktorem. 
      * pobiera druga liczbe do porownania.
      */
    bool operator() (int what) const {
      return (what > thanValue);
    }
};
