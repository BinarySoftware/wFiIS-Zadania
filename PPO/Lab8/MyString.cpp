#include "MyString.h"

#include <iostream>
#include <string.h>


void MyString::set_string(const char * arr){
  int len   = strlen(arr);
  charArray = new char[len+1]();
  strcpy(charArray, arr);
}

char * MyString::str(){
  return charArray;
}

void MyString::swap(MyString & s2){
  char * t     = str();
  charArray    = s2.charArray;
  s2.charArray = t;
}

void MyString::join(MyString & s2){
  char * temp = new char[strlen(str()) + 1 + strlen(s2.str())](); 
  strcat(temp, str());
  strcat(temp, s2.str());
  delete [] str();
  set_string(temp);
  delete [] temp;
}

void MyString::clear_string(){
  std::cout << " - deleting " << str() << std::endl;
  delete [] str();
  charArray = NULL;
}

void MyString::replace(const char * arr){
  delete [] str();
  set_string(arr);
}