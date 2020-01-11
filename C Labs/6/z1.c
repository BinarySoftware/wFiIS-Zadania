//
// Created by Maciej Mikołajek on 08/01/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double *f_min(double *tab, int n);

int main(void){
    unsigned int t = time(NULL);
    srand(t);
    const int tabLen = 10;
    double tab[tabLen];

    for(int i = 0; i<tabLen; i++){
        tab[i] = (double) rand()/RAND_MAX;
        printf("tab[%d] = %.6f, adres elementu: %p\n", i, tab[i], &tab[i]);
    }

    double *min = f_min(tab, tabLen);

    printf("Minimum: tab[%ld] = %.6f, adres elementu: %p\n\n", min - tab, *min,min);

    return 0;
}

double *f_min(double *tab, int n){
    int min = 0;

    for(int i = 0; i<n; i++){
        if(tab[i] < tab[min]){
            min = i;
        }
    }

    return tab+min;
}