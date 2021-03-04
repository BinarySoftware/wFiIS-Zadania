#include "lab06.h"

#include <iostream>
#include <math.h>

using namespace std;

void set(Bits * ptr, int * tab, int size){
  for (int i = 0; i < size; i++){
    ptr->tab[TAB_SIZE-size+i] = tab[i];
  }
  ptr->len = size;
}

void print(const Bits * ptr){
  int ohterThan0 = 0;
  for (int i = TAB_SIZE-ptr->len; i < TAB_SIZE; i++){
    if (ohterThan0 == 0 && ptr->tab[i] == 0){ continue; }
    else { ohterThan0 = 1; }
    std::cout << ptr->tab[i];
  }
  std::cout << std::endl << std::endl;
}

const Bits add_up(const Bits * ptr1, const Bits * ptr2){
  int longest = ptr1->len > ptr2->len ? ptr1->len : ptr2->len;
  int reszta  = 0;

  Bits out = {};

  for (int i = TAB_SIZE-1; i > TAB_SIZE-1-longest; i--){
      int leftPtr1 = i > TAB_SIZE - 1 - ptr1->len;
      int leftPtr2 = i > TAB_SIZE - 1 - ptr2->len;
      int bitPtr1  = leftPtr1 && ptr1->tab[i] ? 1 : 0;
      int bitPtr2  = leftPtr2 && ptr2->tab[i] ? 1 : 0;
      int suma     = bitPtr1 + bitPtr2 + reszta;
      out.tab[i]   = suma == 1 || suma == 3 ? 1 : 0;
      reszta = suma > 1 ? 1 : 0;
  }

  out.tab[TAB_SIZE-1-longest] = reszta;
  out.len = reszta == 0 ? longest : longest + 1;
  return out;
}

void bit_and(Bits * ptr1, Bits * ptr2){
  for (int i = 0; i < ptr1->len; i++){
    ptr1->tab[TAB_SIZE-1-i] = ptr1->tab[TAB_SIZE-1-i] & ptr2->tab[TAB_SIZE-1-i];
  }
}

void bit_xor(Bits * ptr1, Bits * ptr2){
  for (int i = 0; i < ptr1->len; i++){
    ptr1->tab[TAB_SIZE-1-i] = ptr1->tab[TAB_SIZE-1-i] ^ ptr2->tab[TAB_SIZE-1-i];
  }
}

void doOperation(void (&func) (Bits *, Bits *), Bits * ptr1, Bits * ptr2){
  func(ptr1, ptr2);
}

int to_decimal(const Bits * ptr){
  int dec = 0;
  for (int i = 0; i < ptr->len; i++){
    dec += ptr->tab[TAB_SIZE-1-i] * (int)pow(2,i);
  }
  return dec;
}