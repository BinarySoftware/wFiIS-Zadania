//
// Created by Maciej Mikołajek on 18/12/2019.
//

#include <stdio.h>

void r_bin(unsigned int p);

int main() {
    int n;
    printf("Podaj liczbe: ");
    scanf("%d", &n);
    if(n == 0){
        printf("1. bit po prawej: 0\n");
    } else{
        r_bin(n);
    }
    return 0;
}

void r_bin(unsigned int p){
    static int i = 0;
    if(p>0){
        unsigned int bit = p%2;
        i++;
        printf("%d. bit po prawej: %d\n", i, bit);
        r_bin(p >> 1);
    }
}