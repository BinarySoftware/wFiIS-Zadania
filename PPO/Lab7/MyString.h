#pragma once

/**
 * Structure holding a string with it's length.
 */
struct MyString {
  char * str; /**< String packed in this structure. */
};

/**
 * Initializes the structure with given char array.
 *
 * @param s   - the MyString holding element.
 * @param str - the string itself.
 */
void init(MyString & s, const char * str);

/**
 * Concatenates two strings.
 *
 * @param s1 - the MyString number 1.
 * @param s2 - the MyString number 2.
 * @return   - joined s1+s2.
 */
MyString join(const MyString & s1, const MyString & s2);

/**
 * Swaps two MyString's by reference.
 *
 * @param s1 - the MyString number 1.
 * @param s2 - the MyString number 2.
 */
void swap(MyString & s1, MyString & s2);

/**
 * Swaps two MyString's via pointer reference.
 *
 * @param s1 - the MyString number 1.
 * @param s2 - the MyString number 2.
 */
void swap(MyString *&s1, MyString *& s2);

/** a dummy string used as a default value */
extern MyString dummyString;

/**
 * Deletes from 1 up to 5 myStrings.
 *
 * @param s1 - the MyString number 1.
 * @param s2 - the MyString number 2 (optional).
 * @param s3 - the MyString number 3 (optional).
 * @param s4 - the MyString number 4 (optional).
 * @param s5 - the MyString number 5 (optional).
 */
void del(MyString & s1,
         MyString & s2 = dummyString,
         MyString & s3 = dummyString,
         MyString & s4 = dummyString,
         MyString & s5 = dummyString);