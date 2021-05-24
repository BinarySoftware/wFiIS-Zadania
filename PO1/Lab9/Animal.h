#pragma once
#include <string>

/** Klasa Animal - wirtualna klasa do stworzenia zwierzecia na jej podstawie.
 */
class Animal {
  public:
    explicit Animal(const std::string & n): _name(n) {}
    std::string name() const { return _name; }
    virtual void print() const = 0;
  private:
    std::string _name; // Imie przechowywanego zwierzecia
};
