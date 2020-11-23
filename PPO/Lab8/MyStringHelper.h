#pragma once
#include "MyString.h"

/**
 * Class adding more methods for MyString.
 */
class MyStringHelper {
  public:
    /**
     * Replaces current string with another.
     * @param s - MyString instance.
     * @param arr - string to be written into s.
     */
    void replace(MyString & s1, const char * arr);
};


/**
 * Swaps values of two strings.
 * @param s1 - String one
 * @param s2 - String two
 */
void swap(MyString & s1,MyString & s2);