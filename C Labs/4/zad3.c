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
        int pOld = p;
        for(int i = N-1; i>=0; i--){
            int current = p%16;
            switch (current){
                case 10:
                    tab[i] = 'A';
                    break;
                case 11:
                    tab[i] = 'B';
                    break;
                case 12:
                    tab[i] = 'C';
                    break;
                case 13:
                    tab[i] = 'D';
                    break;
                case 14:
                    tab[i] = 'E';
                    break;
                case 15:
                    tab[i] = 'F';
                    break;
                case 1:
                    tab[i] = '1';
                    break;
                case 2:
                    tab[i] = '2';
                    break;
                case 3:
                    tab[i] = '3';
                    break;
                case 4:
                    tab[i] = '4';
                    break;
                case 5:
                    tab[i] = '5';
                    break;
                case 6:
                    tab[i] = '6';
                    break;
                case 7:
                    tab[i] = '7';
                    break;
                case 8:
                    tab[i] = '8';
                    break;
                case 9:
                    tab[i] = '9';
                    break;
                case 0:
                    tab[i] = '0';
                    break;

            }
            p = p >> 4;
        }
        tab[N] = '\0';
        printf("%4d = %s\n", pOld, tab);
    }
}

int main(void){
    for(int i=-2; i<=4097; i++)
        if(i<3 || (i>8 && i<17) || i>4093 || i%1000==0)
            hex(i);
    return 0;
}
