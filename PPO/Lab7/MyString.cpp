#include "MyString.h"
#include <iostream>
#include <string.h>

MyString dummyString;

void init(MyString & s, const char * str){
  int length = strlen(str);
  s.str      = new char[length+1]();
  strcpy(s.str,str);
}

MyString join(const MyString & s1, const MyString & s2){
  MyString s;
  int length = strlen(s1.str) + strlen(s2.str);
  s.str      = new char[length+1]();  
  strcat(s.str,s1.str);
  strcat(s.str,s2.str);
  return s;
}

void swap(MyString & s1, MyString & s2){
  MyString temp = s1;
  s1 = s2;
  s2 = temp;
}

void swap(MyString *&s1, MyString *& s2){
  MyString * temp = s1;
  s1 = s2;
  s2 = temp;
}

void delPrinter(char * str){
  std::cout << "deleting " << str << std::endl;
}

void delHelper(MyString & s){
  if (&s != &dummyString && s.str != NULL){
    delPrinter(s.str);
    delete [] s.str;
    s.str = NULL;
  }
}

void del(MyString & s1,MyString & s2,MyString & s3,MyString & s4,MyString & s5){
  delHelper(s1);
  delHelper(s2);
  delHelper(s3);
  delHelper(s4);
  delHelper(s5);
}