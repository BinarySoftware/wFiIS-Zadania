#pragma once

/**
 * Class holding a string.
 */
class MyString {
  public:
    /**
     * Sets the given char array to field `str`
     * @param arr - char array.
     */
    void set_string(const char * arr);
    /**
     * Getter of string.
     */
    char * str();
    /**
     * Swaps values of two strings.
     * @param s2 - String two
     */
    void swap(MyString & s2);
    /**
     * Joins two strings into one.
     * @param s2 - String two
     */
    void join(MyString & s2);
    /**
     * Clears the string.
     */
    void clear_string();
    /**
     * Replaces current string with another.
     * @param arr - string to be written into s.
     */
    void replace(const char * arr);

  char * charArray; /**< String being held in this class. */
};