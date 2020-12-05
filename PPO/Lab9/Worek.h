#pragma once

#include "Prezent.h"

/** Implementation of LIFO queue.
 *
 * Uses `Prezent` as a single queue node.
 */
class Worek {
  public:
   /** `pop` function implementation for this list.
    *
    * @return - `Prezent` node.
    */

    Prezent Wyciagnij();

   /** `push` function implementation for this list.
    *
    * Pushes `Prezent` into the list, or actually a copy of Prezent.
    * 
    * @param p - `Prezent` to be pushed into the queue.
    */
    void Wloz(Prezent p);

    /** Pointer to the last element of the queue
     */
    Prezent * tail = nullptr;
};