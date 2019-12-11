//
// Created by Maciej Mikołajek on 11/12/2019.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 3

void hex(int p){
    char tab[N+1];
    int max = pow(16,3)-1;
    if (p<0 || p > max){
        printf("liczba %d jest poza zakresem [0,%d]\n", p, max);
    } else {
        int l = p;
        for(int i = N-1; i>=0; i--){
            int current = l%16;

            if (current < 10){
                tab[i] = current + '0';
            } else {
                tab[i] = current + 'A' - 10;
            }

            l = l >> 4;
        }
        tab[N] = '\0';
        printf("%4d = %s\n", p, tab);
    }
}

int main(void){
    for(int i=-2; i<=4097; i++)
        if(i<3 || (i>8 && i<17) || i>4093 || i%1000==0)
            hex(i);
    return 0;
}
