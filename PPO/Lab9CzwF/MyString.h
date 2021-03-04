#pragma once

static int currentID = 0;

/**
 * Class holding a string.
 */
class MyString {
    public:
        /**
         * Creates new myString object with given string.
         * @param arr - char array.
         */
        static MyString create(const char * arr);
        /**
         * Prints out string.
         */
        void print();
        /**
         * Joins two strings into one.
         * @param s2 - String two
         */
        void join(const MyString & s2);
        /**
         * Replaces current string with another.
         * @param arr - string to be written into s.
         */
        void replace(const char * arr);
        /**
         * Class constructor.
         * @param s - string to be written into s.
         */
        MyString(const char * s);
        /**
         * Class destructor.
         */
        ~MyString();
        /**
         * String being held in this class.
         */
        char * charArray;
        /**
         * Id of this string.
         */
        int stringId;
};

/**
 * Swaps values of two strings.
 * @param s2 - String one
 * @param s2 - String two
 */
void swap(MyString & s1, MyString & s2);