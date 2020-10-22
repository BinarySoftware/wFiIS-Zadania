#pragma once


/**
* @brief Wczytuje liczbe wyrazow z konsoli.
*
* @return liczba wyrazow.
*/
int wczytajLiczbeWyrazow();

/**
* @brief Wypisuje dana liczbe w systemie binarnym.
* 
* @param n - liczba wyrazow.
*/
void wypiszBinarnie(int n);

/**
* @brief inicjalizuje tablice.
* 
* Tablica ta sklada sie z kolejnych wyrazow ciagu fibonacciego.
* @param n - liczba wyrazow.
*/
int * inicjalizujCiagFibonacciego(int n);

/**
* @brief wypisuje tablice o podanej dlugosci.
* 
* @param ciag - tablica o dlugosci n.
* @param n - liczba wyrazow.
*/
void wypisz(const int * ciag, int n);

/**
* @brief sumuje wyrazy tablicy.
* 
* @param ciag0 - tablica o dlugosci n.
* @param n0 - liczba wyrazow.
*/
void suma(const int * ciag0, int n0);

/**
* @brief mnozy przez siebie wyrazy tablicy procz pierwszego (0).
* 
* @param ciag0 - tablica o dlugosci n.
* @param n0 - liczba wyrazow.
*/
void iloczyn(const int * ciag0, int n0);

/**
* @brief sumuje wyrazy 2 tablic.
* 
* @param ciag0 - tablica o dlugosci n0.
* @param n0 - liczba wyrazow pierwszej tablicy.
* @param ciag1 - tablica o dlugosci n1.
* @param n1 - liczba wyrazow drugiej tablicy.
*/
void suma(const int * ciag0, int n0, const int * ciag1, int n1);

/**
* @brief znajduje maksymalny element i jego pochodzenie.
* 
* @param ciag0 - tablica o dlugosci n0.
* @param n0 - liczba wyrazow pierwszej tablicy.
* @param ciag1 - tablica o dlugosci n1.
* @param n1 - liczba wyrazow drugiej tablicy.
*/
void max(const int * ciag0, int n0, const int * ciag1, int n1);

/**
* @brief zwalnia pamiec po tablicy.
* 
* @param ciag - tablica (alokowana dynamicznie)
*/
void UsunCiag(const int * ciag);
