//
// Created by Maciej Mikołajek on 04/12/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double d_rand(double min, double max){
    double r = (double) rand()/RAND_MAX;
    return r*(max-min) + min;
}

double rand100(){
    return d_rand(-100.0, 100.0);
}

int main(void){
    unsigned int t = time(NULL);
    srand(t);
    const int tabLen = 10;
    double tab[tabLen];
    printf("%d\n",RAND_MAX);
    printf("Wylosowano tablice:\n");

    for(int i = 0; i<tabLen; i++){
        tab[i] = rand100();
        printf("TAB[%d] = %*.*f\n", i, 7,2, tab[i]);
    }

    int min = 0;
    int max = 0;

    for(int i = 0; i<tabLen; i++){
        if(tab[i] > tab[max]){
            max = i;
        }

        if(tab[i] < tab[min]){
            min = i;
        }
    }

    printf("Indeks najmniejszego elementu: %d, najwiekszego: %d.\n",min,max);
    double prevMax = tab[max];
    tab[max] = tab[min];
    tab[min] = prevMax;

    printf("Tablica po zmianie:\n");
    for(int i = 0; i<tabLen; i++){
        printf("TAB[%d] = %*.*f\n", i, 7,2, tab[i]);
    }

    return 0;
}