#include <iostream>

#include "funkcje.h"



int wczytajLiczbeWyrazow() {
  int n;

  std::cout << "Podaj n: ";
  std::cin >> n;

  return n;
}

void wypiszBinarnie(int n){
  for (int i = 0; n > 0; i++){
    std::cout << n%2;
    n = n/2;
  }
}

int * inicjalizujCiagFibonacciego(int n){
  int * tab = new int[n+1];
  tab[0] = 0;
  tab[1] = 1;
  for (int i = 2; i <= n; i++) {
    tab[i] = tab[i-1] + tab[i-2];
  }
  return tab;
}

void wypisz(const int * ciag,int n){
  std::cout << "(";
  for (int i = 0; i <= n; i++) {
    std::cout << ciag[i];
    if (i < n) {
      std::cout << ", ";
    }
  }
  std::cout << ") " << std::endl;
}

void suma(const int * ciag0, int n0){
  int s = 0;
  for (int i = 0; i <= n0; i++) {
    s += ciag0[i];
  }
  std::cout << "suma: " << s << std::endl;
}

void iloczyn(const int * ciag0, int n0){
  int s = 1;
  for (int i = 1; i <= n0; i++) {
    s *= ciag0[i];
  }
  std::cout << "iloczyn: " << s << std::endl;
}

void suma(const int * ciag0, int n0, const int * ciag1, int n1){
  int s = 0;
  for (int i = 0; i <= n0; i++) {
    s += ciag0[i];
  }
  for (int i = 0; i <= n1; i++) {
    s += ciag1[i];
  }
  std::cout << "suma dwoch ciagow: " << s << std::endl;
}

void max(const int * ciag0, int n0, const int * ciag1, int n1){
  int max = ciag0[0];
  std::string ciagMax = "ciag0";
  for (int i = 0; i <= n0; i++) {
    if (ciag0[i] > max) {
      max = ciag0[i];
    }
  }
  for (int i = 0; i <= n1; i++) {
    if (ciag1[i] > max) {
      max = ciag1[i];
      ciagMax = "ciag1";
    }
  }
  std::cout << "maksimum: " << max << " (" << ciagMax << ")" << std::endl;
}

void UsunCiag(const int * ciag){
  delete[] ciag;
}