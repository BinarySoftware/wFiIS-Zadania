#pragma once

#define TAB_SIZE 32

/**
 * Structure holding binary representation of a number.
 */
struct Bits {
  int tab[TAB_SIZE]; /**< Array holding number bit-by-bit. */
  int len; /**< Length of the binary representation.  */
};

/**
 * Sets fields of `Bits`
 * 
 * @param ptr - pointer to Bits Structure.
 * @param tab - array of bits.
 * @param size - length of given array.
 */
void set(Bits * ptr, int * tab, int size);

/**
 * Prints out `Bits` on user's screen.
 * 
 * @param ptr - pointer to Bits Structure.
 */
void print(const Bits * ptr);

/**
 * Creates new `Bits` structure holding value of addition of two other bits.
 * 
 * @param ptr1 - pointer to first Bits Structure.
 * @param ptr2 - pointer to second Bits Structure.
 */
const Bits add_up(const Bits * ptr1, const Bits * ptr2);

/**
 * Makes bitwise AND on two binary numbers.
 * 
 * @param ptr1 - pointer to first Bits Structure.
 * @param ptr2 - pointer to second Bits Structure.
 */
void bit_and(Bits * ptr1, Bits * ptr2);

/**
 * Makes bitwise bit_xor on two binary numbers.
 * 
 * @param ptr1 - pointer to first Bits Structure.
 * @param ptr2 - pointer to second Bits Structure.
 */
void bit_xor(Bits * ptr1, Bits * ptr2);

/**
 * Runs operation on two binary numbers.
 * 
 * @param func - operation to pass the Bits to.
 * @param ptr1 - pointer to first Bits Structure.
 * @param ptr2 - pointer to second Bits Structure.
 */
void doOperation(void (&func) (Bits *, Bits *), Bits * ptr1, Bits * ptr2);

/**
 * Converts binary representation to decimal.
 * 
 * @param ptr - pointer to Bits Structure.
 */
int to_decimal(const Bits * ptr);