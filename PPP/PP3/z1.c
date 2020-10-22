//
// Created by Maciej Mikołajek on 10/03/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wypisz_i (int *poczatek, int *koniec) {
    while (poczatek < koniec) {
        printf("%4d", *poczatek++);
    }
    printf ("\n");
}

int suma (int *tab, int len) {
    int ss = 0;
    for (int i = 0; i < len; i++){
        ss+= tab[i];
    }
    return ss;
}

int int_rand(int min, int max ){
    return rand() % (max + abs(min)) + min;
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    srand(time(0));
    int abc[5][5];
    int suma_abc[5];
    printf("Tablica ABC:\n");
    for (int i = 0; i<5; i++){
        for (int j = 0; j<5; j++){
            abc[i][j] = int_rand(-10,10);
        }
        wypisz_i(abc[i],abc[i]+5);
        suma_abc[i] = suma(abc[i], 5);
    }

    printf("SUMA ABC Wierszy:\n");
    wypisz_i(suma_abc, suma_abc + sizeof(suma_abc)/ sizeof(int));
    int suma_all = suma(suma_abc, sizeof(suma_abc)/ sizeof(int));
    printf("SUMA All po wierszach: %d\n", suma_all);

    printf("Tablica ABC Transponowana:\n");
    int suma_abc_kol[5];
    for (int i = 0; i<5; i++){
        for (int j = i; j<5; j++){
            swap(abc[i]+j, abc[j]+i);
        }
        wypisz_i(abc[i],abc[i]+5);
        suma_abc_kol[i] = suma(abc[i], 5);
    }
    printf("SUMA ABC Kolumn:\n");
    wypisz_i(suma_abc_kol, suma_abc_kol + sizeof(suma_abc_kol)/ sizeof(int));
    int suma_po_kolumnach = suma(suma_abc_kol, sizeof(suma_abc_kol)/ sizeof(int));
    printf("SUMA All po kolumnach: %d\n", suma_po_kolumnach);
    if(suma_all == suma_po_kolumnach){
        printf("Takie same sumy\n");
    }else{
        printf("Rozne sumy\n");
    }

    printf("Przekatna i elementy pod nią:\n");
    for (int i = 0; i<5; i++){
        wypisz_i(abc[i],abc[i]+i+1);
    }

    return 0;
}
