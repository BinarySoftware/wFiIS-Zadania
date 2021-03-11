#include "ComplexNumber.h"

   
ComplexNumber ComplexNumber::operator++() {
  r += 1;
  return *this;
}

ComplexNumber ComplexNumber::operator++(int) {
  ComplexNumber temp = *this;
  ++temp;
  return temp;
}

double & ComplexNumber::operator[](int i){
  if (i == 0 ) {
    return r;
  }
  return im;
}

void ComplexNumber::operator*=(int i) {
  r  *= i;
  im *= i;
}