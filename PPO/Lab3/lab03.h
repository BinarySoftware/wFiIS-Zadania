#pragma once

/**
 * Creates fibonacci sequence.
 */
const int * initFibonacci(int len);

/**
 * Prints sequence of given length.
 */
void print(const int * sequence, int abs_n);

/**
 * Deletes sequence.
 */
void deleteSequence(const int * sequence);

/**
 * Adds sequence.
 */
void addSequence(int * numberOfSequences, int *** sequencesList, int ** sequencesLength, int newLength);

/**
 * Prints all sequences.
 */
void printAllSequences(int ** sequencesList, int * sequencesLenght,int numberOfSequences);

/**
 * Deletes given sequence.
 */
void removeSequence(int * numberOfSequences, int *** sequencesList, int ** sequencesLength, int n);

/**
 * Deletes all sequences.
 */
void deleteSequences(int * numberOfSequences, int *** sequencesList, int ** sequencesLength);
