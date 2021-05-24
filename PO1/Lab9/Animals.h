#pragma once
#include "Animal.h"


/** Owca.
*/
class Sheep : public Animal {
  public:
    ~Sheep();
    Sheep(const std::string & name) : Animal(name), isSheared(false) {}

    /** Drukuje na ekranie owce.
    */
    void print() const override;

    /** Strzyze owce.
    */
    void shear();
  private:
    bool isSheared;
};

/** Krowa.
*/
class Cow : public Animal {
  public:
    ~Cow();
    Cow(const std::string & name) : Animal(name) {}

    /** Drukuje na ekranie krowe.
    */
    void print() const override;
};

/** Koń.
*/
class Horse : public Animal {
  public:
    ~Horse();
    Horse(const std::string & name) : Animal(name) {}

    /** Drukuje na ekranie konia.
    */
    void print() const override;
};