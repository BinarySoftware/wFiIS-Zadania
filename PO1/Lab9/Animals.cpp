#include "Animals.h"
#include <iostream>

void Sheep::shear(){
  isSheared = true;
}

void Sheep::print() const{
 std::cout << "- Owca " << name() << " ";
 isSheared ? std::cout << "ostrzyzona " : std::cout << "nieostrzyzona ";
}

void Cow::print() const{
  std::cout << "- Krowa " << name() << " ";
}

void Horse::print() const{
  std::cout << "- Kon " << name() << " ";
}

Sheep::~Sheep(){
  print();
  std::cout << "wraca do zagrody";
}

Cow::~Cow(){
  print();
  std::cout << "wraca do obory";
}

Horse::~Horse(){
  print();
  std::cout << "wraca do stajni";
}