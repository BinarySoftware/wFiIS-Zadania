#pragma once
#include <iostream>

/**
 * Class holding a string.
 */
class MyString {
  public:
    void set_string(const char * arr){
      int len   = strlen(arr);
      charArray = new char[len+1]();
      strcpy(charArray, arr);
    }

    char * str(){
      return charArray;
    }

    MyString(const char * arr) {
      set_string(arr);
    }

    // ~MyString(){
    //   delete[] charArray;
    // }

    friend std::ostream& operator<<(std::ostream& os, MyString const & tc) {
        return os << tc.charArray;
    }

    friend MyString operator+(MyString &s1, MyString &s2) {
        char * temp = new char[strlen(s1.str()) + 1 + strlen(s2.str())](); 
        strcat(temp, s1.str());
        strcat(temp, s2.str());
        return MyString(temp);
    }

    friend MyString operator*(int i, MyString &s) {
        char * temp = new char[strlen(s.str())*i + 1](); 
        for(int j=0; j<i;j++){
           strcat(temp, s.str());
        }
        return MyString(temp);
    }

    friend void operator*(MyString &s,int i) {
      char * temp = new char[strlen(s.str())*i + 1](); 
      for(int j=0; j<i;j++){
          strcat(temp, s.str());
      }
      s.set_string(temp);
    }

    friend bool operator==(MyString &s,const char * arr) {
        int val = strcmp(s.str(),arr);
        return val == 0;
    }

  private:
    char * charArray; /**< String being held in this class. */
};