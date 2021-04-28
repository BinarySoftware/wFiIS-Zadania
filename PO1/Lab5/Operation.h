#pragma once
#include <iostream>

/** Klasa operation. */
class Operation {
  public:
    /** Umozliwia pretty-prinring dzialania.
        @param s string przed i po dzialaniu
        @param o operacja
    */
    friend void operator >>= (const char * s, const Operation& o){
      std::cout << s << " ";
      o.print();
      std::cout << " " << s << std::endl;
    }

    /** Drukuje dzialanie na ekran.
    */
    virtual void print() const {}

    /** Wylicza wynik z dzialania.
    */
    virtual double eval() const { return 0; }
};