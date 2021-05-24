#pragma once
#include <iostream>

/**
 * Przydatne funkcje dla tablic liczbowych.
 */
namespace num {
  /** Wyznacza srednia wartosc z danej tablicy.
   *
   * @param container - tablica.
   * @param size - jej rozmiar.
   * @return srednia wartosc.
   */
  template <typename T> double srednia(T * contatiner, int size){
    double sum = 0;
    for(int i = 0; i < size; i++){
      sum += contatiner[i];
    }
    return sum / size;
  }

  /** Wyznacza srednia wartosc z danej tablicy (const).
   *
   * @param container - tablica.
   * @param size - jej rozmiar.
   * @return srednia wartosc.
   */
  template <typename T> double srednia(const T * contatiner, int size){
    double sum = 0;
    for(int i = 0; i < size; i++){
      sum += contatiner[i];
    }
    return sum / size;
  }

   /** Wyznacza srednia wartosc z danej tablicy, wyliczajac jej rozmiar.
   *
   * @param container - tablica.
   * @return srednia wartosc.
   */
  template <typename T> double srednia(T * contatiner){
    double sum = 0;
    int size = 0;
    while(contatiner[size] < 1000 && contatiner[size] > -1000){
      size++;
    }
    for(int i = 0; i < size; i++){
      sum += contatiner[i];
    }
    return sum / size;
  }

  /** Sprawdza czy wszystkie elementy w tablicy to liczby pierwsze.
   *
   * @param container - tablica.
   * @return czy wszystkie pierwsze.
   */
  template <int a, int b> bool czyWszystkiePierwsze(int * contatiner){
    int size = *(&contatiner+1)-contatiner;
    if (a < 0 || b < 0 || a > size || b > size || a > b){
      std::cout << "Nieprawidlowy zakres!" << std::endl;
      return false;
    }
    for (int i = a; i < b; i++){
      for(int j = 2; j < contatiner[i]; j++){
        if(contatiner[i]%j == 0){
          return false;
        }
      }
    }
    return true;
  }

  /** Pretty-printer wartosci prawda-falsz.
   *
   * @param b - wartosc logiczna.
   * @return ciag z wartosci.
   */
  char * text(bool b){
    if (b == true){
      return "TRUE";
    }
    return"FALSE";
  }

}