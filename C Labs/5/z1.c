//
// Created by Maciej Mikołajek on 18/12/2019.
//

#include <stdio.h>

int main() {
    unsigned int i;
    printf("Podaj liczbę: ");
    scanf("%u", &i);
    printf("\n");
    while(getchar()!='\n');

    int sizeof_i = sizeof(i)*8;

    printf("stara liczba: %u\n", i);
    unsigned int j = 3; // 0..011
    j = j << (sizeof_i/2-1);
    i = i | j;
    printf("nowa liczba: %u\n", i);
    return 0;
}