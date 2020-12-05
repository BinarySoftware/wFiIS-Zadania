#include "Worek.h"

#include <iostream>

Prezent Worek::Wyciagnij(){
  Prezent retPrezent = Prezent(-1);
  if (tail == nullptr) {
    std::cout << "Niestety, prezenty juz sie skonczyly." << std::endl;
    return retPrezent;
  }
  Prezent * prezentPtr = tail;
  tail = tail->prev;
  retPrezent = Prezent(*prezentPtr);
  delete prezentPtr;
  return retPrezent;
}

void Worek::Wloz(Prezent p){
  Prezent * newPrezent = new Prezent(p);
  newPrezent->prev = tail;
  tail = newPrezent;
}
