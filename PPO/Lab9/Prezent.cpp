#include "Prezent.h"

#include <iostream>

void Prezent::NapiszIleJestPrezentow(){
  std::cout << "Aktualna liczba prezentow: " << currentNumberOfGifts << std::endl;
}

void Prezent::Wypisz(){
  std::cout << "Ten prezent kosztuje: " << getValue() << std::endl;
}

int Prezent::getValue(){
  return _value;
}

Prezent::Prezent(const int val){
  currentNumberOfGifts++;
  _value = val;
  prev = nullptr;
}

Prezent::Prezent(Prezent & p){
  currentNumberOfGifts++;
  _value = p.getValue();
  prev = nullptr;
}

Prezent::~Prezent(){
  currentNumberOfGifts--;
}
