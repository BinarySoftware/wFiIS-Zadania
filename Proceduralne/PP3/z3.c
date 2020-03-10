//
// Created by Maciej Mikołajek on 10/03/2020.
//

#include <stdio.h>
#include <stdlib.h>

double double_rand(){
    double scale = rand() / (double) RAND_MAX;
    return scale;
}

void wypelnij(double TAB[][6], int il_wierszy){
    double begin = double_rand();
    for(int i = 0; i < il_wierszy*6 ; i++) {
        (*TAB)[i] = begin + i*0.4;
    }
}

void wypisz_d (double *poczatek, double *koniec) {
    while (poczatek < koniec){
        printf ("%6.2f", *poczatek++);
    }
    printf ("\n");
}

int main() {
    double A_1[8][6];
    double A_2[10][6];

    wypelnij(A_1, 8);
    wypelnij(A_2, 10);

    printf("A_1:\n");
    for (int i = 0; i < 8; i++){
        wypisz_d(A_1[i], A_1[i] + 6);
    }

    printf("A_2:\n");
    for (int i = 0; i < 10; i++){
        wypisz_d(A_2[i], A_2[i] + 6);
    }
    return 0;
}
