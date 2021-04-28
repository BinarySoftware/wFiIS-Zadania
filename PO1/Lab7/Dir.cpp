#include "Dir.h"

Dir::~Dir(){
  std::cout << "Destruktor: " << name << std::endl;
  for(File * f : tree){
    delete f;
  }
}

void Dir::copy(File * f){

}

void Dir::operator+=(File * f){
  tree.push_back(f);
}

void Dir::operator-=(std::string s){

}

Dir * Dir::getDir(std::string s){
  // std::find(tree.begin(), tree.end(), Dir(s));
}

File * Dir::get(std::string s){

}
