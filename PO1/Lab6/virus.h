#pragma once
#include "rna.h"
#include <vector>
#include <string>

class Virus {
  public: 
    /// Konstruktor glowny bez parametrow.
    Virus(): name(""), rna(NULL) {};
    /** Konstruktor glowny z wartosci
        @param n nazwa wirusa
    */
    Virus(std::string n): name(n), rna(NULL) {};
    /// Konstruktor kopiujacy
    Virus(Virus &v): name(v.name), age(0) {
      if(v.rna) { rna = new RNA(v.rna->mutate().get_RNA());};
      v.age++;
    };
    /// Konstruktor przenoszacy
    Virus(Virus &&v): name(std::move(v.name)), age(std::move(v.age)), rna(v.rna) {};

    /// @return `name`
    std::string get_name() const;

    /// @return `age`
    int get_age() const;

    /// @return `rna`
    RNA * get_RNA() const;

    /// Ustawia wartosc `rna`
    void set_RNA(std::vector<Nukleotyp> v);
  protected:
    std::string name; // Przetrzymuje nazwe wirusa
    int age; // Przetrzymuje wiek wirusa
    RNA * rna; // Przetrzymuje RNA
};
