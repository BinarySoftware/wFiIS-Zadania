#include "animalvirus.h"
#include <string>

AnimalVirus &AnimalVirus::operator=(AnimalVirus &v){
  host = v.get_animal_host();
  age = v.get_age();
  set_RNA(v.get_RNA()->get_RNA());
  name = v.get_name();
  return *this;
}

 AnimalVirus &AnimalVirus::operator=(AnimalVirus &&v){
  host = v.get_animal_host();
  age = v.get_age();
  set_RNA(v.get_RNA()->get_RNA());
  name = v.get_name();
  return *this;
 }

std::string AnimalVirus::get_animal_host() const{
  return host;
}
