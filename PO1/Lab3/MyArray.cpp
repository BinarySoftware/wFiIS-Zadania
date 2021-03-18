#include "MyArray.h"
#include <iostream>

MyArray::~MyArray(){
  delete[] tab;
}

int & MyArray::operator[](int i){
  return tab[i];
}

const int & MyArray::operator[](int i) const{
  return tab[i];
}

MyArray MyArray::operator++(int){
  MyArray c = MyArray(*this);
  for (int i=0; i<c.size(); i++){
    c[i] = c[i] + 1;
  }
  return c;
}

MyArray MyArray::operator--(){
  for (int i=0; i<_size; i++){
    tab[i] = tab[i] - 1;
  }
  return *this;
}

MyArray::MyArray(const MyArray & a){
  _size = a._size;
  tab = new int[_size];
  for (int i=0; i<_size; i++){
    tab[i] = a.tab[i];
  }
}

MyArray::MyArray(MyArray && a){
  _size = std::move(a._size);
  tab   = std::move(a.tab);
}

MyArray & MyArray::operator=(MyArray & a){
  _size = a._size;
  tab = new int[_size];
  for (int i=0; i<_size; i++){
    tab[i] = a.tab[i];
  }
  return *this;
}

void MyArray::print(std::string s){
  std::cout << s << *this;
}

// MyArray MyArray::operator+=(MyArray & a){
//   sizeOfsize++;
//   _size[sizeOfsize-1] = a._size[0];
//   int tabCap = 0;
//   for (int i = 0; i<sizeOfsize; i++) { tabCap += _size[i]; }
//   tabCap += a._size[0];
//   int * newTab = new int[tabCap];
//   for (int i = 0; i<tabCap-a._size[0]; i++) { newTab[i] = tab[i]; }
//   for (int i = tabCap-a._size[0]; i<tabCap; i++) { newTab[i] = a.tab[i]; }
//   delete[] tab;
//   *tab = *newTab;
//   return *this;
// }
