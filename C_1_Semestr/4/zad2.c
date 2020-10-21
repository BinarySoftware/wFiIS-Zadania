//
// Created by Maciej Mikołajek on 11/12/2019.
//

#include <stdio.h>
#include <math.h>

unsigned int count1(unsigned int p);

int main() {
    unsigned int p;
    p = 2071;

    printf("liczba %d ma %d jedynek\n",p, count1(p));
}

unsigned int count1(unsigned int p){
    int jedynki = 0;
    int length = log2(p)+1;

    for(int i = length; i>=0; i--){
        int current = p%2;
        switch (current){
            case 1:
                jedynki += 1;
                break;
            default:
                break;
        }
        p = p >> 1;
    }

    return jedynki;
}
