#include "Meadow.h"
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>


void Meadow::add(std::unique_ptr<Animal> a){
  allAnimals.push_back(std::move(a));
}

void Meadow::print(const std::string & s){
  std::cout << "== " << s << " ==";
  std::for_each(allAnimals.begin(), allAnimals.end(), [](const std::unique_ptr<Animal>& animal) { 
    std::cout << std::endl; animal->print();
  });
  std::cout << std::endl;
}

void Meadow::countNames(){
  std::vector<std::string> names;
  for(auto & animal : allAnimals){
    names.push_back(animal->name());
  } 
  std::sort(names.begin(), names.end());
  std::set<std::string> uniqueNames(names.begin(), names.end());
  for(auto & name : uniqueNames){
    std::cout << name << ": " << std::count(names.begin(), names.end(), name) << std::endl;
  }
}

std::vector<Sheep *> Meadow::getSheepHerd(){
  std::vector<Sheep *> herd;
  for(auto & animal : allAnimals){
    auto maybeSheep = dynamic_cast<Sheep*>(animal.get());
    if(maybeSheep) {
      herd.push_back(maybeSheep);
    }
  }
  return herd;
}
