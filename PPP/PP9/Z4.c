//
// Created by Maciej Mikołajek on 28/04/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/// WEKTOR i ABC
typedef struct {
    double x;
    double y;
    double z;
} wektor;

typedef struct {
    wektor w;
    double len;
} abc;


/// GENERACJA RANDOMOWYCH WEKTOROW
double randDouble(double min, double max){
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

wektor randWektor(){
    double x = randDouble(-10,10);
    double y = randDouble(-10,10);
    double z = randDouble(-10,10);
    wektor w = {x, y, z};
    return w;
}

/// DLUGOSCI DLA ABC
double wekt_len (wektor w){
    return sqrt(w.x*w.x + w.y*w.y + w.z*w.z);
}

void f_d (abc * a, int l){
    for (int i = 0; i < l; ++i) {
        a[i].len = wekt_len(a[i].w);
    }
}

/// PRINT ABC
void printAbc(int nrStr, abc a){
    printf("%d) x: %7.2f y: %7.2f z: %7.2f, dlugosc: %.2f\n", nrStr, a.w.x, a.w.y, a.w.z, a.len);
}

/// KOMPARATOR
int abc_cmp(const void * a, const void * b){
    abc *abcA = (abc *)a;
    abc *abcB = (abc *)b;

    if (abcA->len > abcB->len) return 1;
    else if (abcA->len < abcB->len) return -1;
    else return 0;
}


/// MAIN
int main(int argc, char *argv[]) {
    srand(time(NULL));
    if (argc < 2){
        printf("Prosze podac argument.");
        return 1;
    }

    // Alokacja i tworzenie tablicy losowych abc
    int tabLen = atoi(argv[1]);
    abc * tab = malloc(tabLen*sizeof(abc));
    for (int i = 0; i < tabLen; ++i) {
        wektor w = randWektor();
        abc abc1 = {w,0};
        tab[i] = abc1;
    }

    // wyliczanie dlugosci wektorow w tablicy
    f_d(tab, tabLen);
    printf("Tablica\n");
    for (int i = 0; i < tabLen; ++i) {
        printAbc(i, tab[i]);
    }

    // sortowanie tablicy
    qsort(tab,tabLen,sizeof(abc), abc_cmp);
    printf("\nPo posortowaniu\n");
    for (int i = 0; i < tabLen; ++i) {
        printAbc(i, tab[i]);
    }
    return 0;
}