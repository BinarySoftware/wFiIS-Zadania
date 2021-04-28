#include "virus.h"
#include "rna.h"
#include <vector>
#include <string>


std::string Virus::get_name() const{
  return name;
}

int  Virus::get_age() const{
  return age;
}

RNA * Virus::get_RNA() const{
  return rna;
}

void Virus::set_RNA(std::vector<Nukleotyp> v){
  rna = new RNA(v);
}
