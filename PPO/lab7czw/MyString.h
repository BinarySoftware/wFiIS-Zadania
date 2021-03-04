#pragma once

/**
 * Structure holding a string.
 */
struct MyString {
  char * str; /**< String packed in this structure. */
  int length; /**< String's length. */
};

/**
 * Initializes MyString with char array.
 * 
 * @param s   - the MyString string holding element.
 * @param str - the string itself.
 */
void init(MyString & s, const char * str);

/**
 * Joins two strings and creates new one from joint.
 * 
 * @param s1 - String 1
 * @param s2 - String 2
 * @return   - joined strings.
 */
MyString join(const MyString & s1, const MyString & s2);

/**
 * Swaps strings by references.
 * 
 * @param s1 - String 1
 * @param s2 - String 2
 */
void swap(MyString & s1, MyString & s2);

/**
 * Swaps addresses of pointers to strings.
 * 
 * @param s1 - String 1
 * @param s2 - String 2
 */
void swap(MyString*& s1, MyString*& s2);

/** A dummy string used as a default value */
static MyString dummyString;

/**
 * Deletes strings from memory.
 * 
 * @param s1 - String 1
 * @param s2 - (Optional) String 2
 * @param s3 - (Optional) String 3
 * @param s4 - (Optional) String 4
 * @param s5 - (Optional) String 5
 */
void del(MyString & s1,
         MyString & s2 = dummyString,
         MyString & s3 = dummyString,
         MyString & s4 = dummyString,
         MyString & s5 = dummyString);