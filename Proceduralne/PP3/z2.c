//
// Created by Maciej Mikołajek on 10/03/2020.
//

#include <stdio.h>

void wypisz_d (double *poczatek, double *koniec) {
    while (poczatek < koniec){
        printf ("%6.2f", *poczatek++);
    }
    printf ("\n");
}

double suma (double ** tab, int nr_tab, int len) {
    double ss = 0;
    for (int i = 0; i < len; i++){
        ss+= tab[nr_tab][i];
    }
    return ss;
}

double * find_tab (double ** tab, int len) {
    int min = 0;
    for (int i = 0; i < len; i++){
        double ss = suma(tab, i, 4);
        if (ss<suma(tab, min, 4)){
            min = i;
        }
    }
    return tab[min];
}

void swap(double *a, double *b, int len ){
    for ( int i = 0; i < len; i++ ){
        double tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;
    }
}

void find_tab_1(double ** tab, int poczatkowa, int len) {
    int min = poczatkowa;
    for (int i = poczatkowa; i < len; i++){
        double ss = suma(tab, i, 4);
        if (ss<suma(tab, min, 4)){
            min = i;
        }
    }
    swap(tab[poczatkowa], tab[min], 4);
}

int main() {
    double T_1[4] = {1.0, 3.0, 2.0, 1.5};
    double T_2[4] = {1.8, 2.0, 1.2, 3.8};
    double T_3[4] = {5.6, 1.0, 3.3, 3.3};
    double T_4[4] = {1.1, 2.1, 6.5, 1.7};
    double T_5[4] = {6.7, 7.8, 9.1, 1.0};

    double * TAB[5];
    TAB[0] = T_1;
    TAB[1] = T_2;
    TAB[2] = T_3;
    TAB[3] = T_4;
    TAB[4] = T_5;

    for (int i = 0; i < sizeof(TAB)/sizeof(double); i++){
        for (int j = 0; j<4; j++)
            printf("%.2f ", TAB[i][j]);
        printf ("\n");
    }

    double ** TABLICA = TAB;
    for (int i = 0; i < 5; i++){
        wypisz_d(TABLICA[i], TABLICA[i] + 4);
    }

    for (int i = 0; i < 5; i++){
        printf("Suma wartosci w tablicy T_%d : %.2f\n",i ,suma(TAB, i, 4));
    }

    double * min = find_tab(TAB, 5);
    printf("Najmniejsza tablica:\n");
    wypisz_d(min, min + 4);

    for (int k = 0; k < 5 ; k++) {
        find_tab_1(TAB, k, 5);
    }

    for (int i = 0; i < 5; i++){
        printf("Suma wartosci w tablicy T_%d : %.2f\n",i ,suma(TAB, i, 4));
    }

    return 0;
}
