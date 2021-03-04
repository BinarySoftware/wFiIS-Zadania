#include "MyString.h"

#include <iostream>
#include <string.h>

void init(MyString & s, const char * str){
    s.length = strlen(str);
    s.str    = new char[s.length + 1]();
    strcpy(s.str, str);
}

MyString join(const MyString & s1, const MyString & s2){
    MyString s;
    s.length = strlen(s1.str)+strlen(s2.str)+1;
    s.str    = new char[s.length]();
    strcat(s.str, s1.str);
    strcat(s.str, s2.str);
    return s;
}

void swap(MyString & s1, MyString & s2){
  MyString temp = s1;
  s1 = s2;
  s2 = temp;
}

void swap(MyString *& s1, MyString *& s2){
    MyString * temp = s1;
    s1 = s2;
    s2 = temp;
}

void delPrinter(char * str){
    std::cout << "deleting " << str << std::endl;
}

void del(MyString & s1,
         MyString & s2,
         MyString & s3,
         MyString & s4,
         MyString & s5){
             if (s2.str != NULL) { delPrinter(s1.str); delete [] s1.str; s1.str = NULL;}
             if (s2.str != NULL) { delPrinter(s2.str); delete [] s2.str; s2.str = NULL;}
             if (s3.str != NULL) { delPrinter(s3.str); delete [] s3.str; s3.str = NULL;}
             if (s4.str != NULL) { delPrinter(s4.str); delete [] s4.str; s4.str = NULL;}
             if (s5.str != NULL) { delPrinter(s5.str); delete [] s5.str; s5.str = NULL;}
         }