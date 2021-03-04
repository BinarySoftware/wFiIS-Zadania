#include "MyString.h"

#include <iostream>

MyString MyString::create(const char * arr){
    return MyString(arr);
}

void MyString::print(){
    std::cout << " ID: " << this->stringId << " str: " << this->charArray << std::endl;
}

void MyString::join(const MyString & s2){
  char * temp = new char[strlen(charArray) + 1 + strlen(s2.charArray)]; 
  strcat(temp, charArray);
  strcat(temp, s2.charArray);
  delete [] charArray;
  charArray = temp;
}

void MyString::replace(const char * arr){
    delete [] charArray;
    int len   = strlen(arr);
    charArray = new char[len+1]();
    strcpy(charArray, arr);
}

MyString::MyString(const char * s){
    int len   = strlen(s);
    charArray = new char[len+1]();
    strcpy(charArray, s);
    currentID++;
    stringId = currentID;
}

MyString::~MyString(){
    std::cout << " - deleting " << this->charArray << std::endl;
    delete [] this->charArray;
}

void swap(MyString & s1, MyString & s2){
    char * t     = s1.charArray;
    s1.charArray = s2.charArray;
    s2.charArray = t;
}