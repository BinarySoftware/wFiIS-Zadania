#pragma once

/** Holds current number of gifts in memory.
  */
static int currentNumberOfGifts = 0;

/** Holds a single 'Prezent' object.
 * 
 * Class Prezent is used as a single node for queue implemented 
 * as class 'Worek.
 */
class Prezent {
  public:
    /** `Prezent`'s initializer.
     * @param val - value taken for _value.
     */
    Prezent(int val);

     /** `Prezent`'s copy initializer.
     * @param p - reference to another `Prezent` object.
     */
    Prezent(Prezent & p);

    /** Prints out the `currentNumberOfGifts` onto user's screen.
     */
    void NapiszIleJestPrezentow();

    /** Prints out the current `Prezent` object onto user's screen.
     */
    void Wypisz();

    /** Getter for _value.
     * @return - _value
     */
    int getValue();

    /** `Prezent`'s destructor..
     */
    ~Prezent();

    /** Pointer to previous `Prezent` int the queue.
     */
    Prezent * prev;
  private:
    int _value; /**< Value held by this node. */
};