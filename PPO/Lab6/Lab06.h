#pragma once

#define TAB_SIZE 32

/**
 * Structure used to hold binary numbers.
 */
struct Bits {
  int tab[TAB_SIZE]; /**< Array holding binary representation of a number.*/
  int len; /**< Length of given binary number*/
};

typedef void (*function) (Bits *, const Bits *);

/**
 * Sets the values on fields of `Bits`.
 *
 * @param ptr - pointer to the `Bits`.
 * @param tab - array holding the binary number.
 * @param size - size of the array.
 */
void set(Bits * ptr, int * tab, int size);

/**
 * Prints the binary number out.
 *
 * @param ptr - pointer to the `Bits`.
 */
void print(const Bits * ptr);

/**
 * Adds two binary numbers.
 *
 * @param ptr1 - pointer to the first `Bits`.
 * @param ptr1 - pointer to the second `Bits`.
 * @return - summed up number.
 */
const Bits add_up(const Bits * ptr1, const Bits * ptr2);

/**
 * Runs AND logical operation on two binary numbers.
 *
 * @param ptr1 - pointer to the first `Bits`.
 * @param ptr1 - pointer to the second `Bits`.
 */
void bit_and(Bits * ptr1, const Bits * ptr2);

/**
 * Runs XOR logical operation on two binary numbers.
 *
 * @param ptr1 - pointer to the first `Bits`.
 * @param ptr1 - pointer to the second `Bits`.
 */
void bit_xor(Bits * ptr1, const Bits * ptr2);

/**
 * Runs given operation on two binary numbers.
 *
 * @param func - function to which the bits will be passed.
 * @param ptr1 - pointer to the first `Bits`.
 * @param ptr1 - pointer to the second `Bits`.
 */
void doOperation(function func,Bits * ptr1, const Bits * ptr2);

/**
 * Converts the binary number to decimal representation.
 *
 * @param ptr - pointer to the `Bits`.
 * @return - decimal value.
 */
int to_decimal(const Bits * ptr);
