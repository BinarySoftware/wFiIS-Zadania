#pragma once
#include "virus.h"
#include <string>

class AnimalVirus: public Virus {
  public:
    /// Konstruktor glowny
    AnimalVirus(): Virus(), host("") {};
    /** Konstruktor glowny z wartosci
        @param n nazwa wirusa
        @param h host wirusa
        @param v wektor nukleotypow
    */
    AnimalVirus(std::string n, std::string h, std::vector<Nukleotyp> v): Virus(n), host(h) { set_RNA(v); };
    /// Konstruktor kopiujacy
    AnimalVirus(AnimalVirus &av):Virus(av), host(av.host) {};
    /// Konstruktor przenoszacy
    AnimalVirus(AnimalVirus &&av):Virus(std::move(av)), host(av.host) {};

    AnimalVirus &operator=(AnimalVirus &v);

    AnimalVirus &operator=(AnimalVirus &&v);

    /// @return `host`.
    std::string get_animal_host() const;
  private:
    std::string host;
};
