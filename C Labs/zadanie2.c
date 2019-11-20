//
// Created by Maciej Mikołajek on 20/11/2019.
//

#include <stdio.h>
#include <limits.h>

int main(void){
    char znak = '7';
    int D;

    printf("Zakres liczb typu char: od %d do %d.\n", CHAR_MIN, CHAR_MAX);

    printf("%d to %c\n", znak, znak);

    znak = 7;
    printf("%d to %c\n\n", znak, znak);

    znak = 'A';
    printf("%d to %c\n", znak, znak);

    znak = znak+1;
    printf("%d to %c\n", znak, znak);

    D = 67;
    printf("%d to %c\n", D, D);

    znak = D;
    printf("%d to %c\n", znak, znak);

    printf("Wszystkie znaki:");
    for (int i = -128; i < 128 ; ++i) {
        printf("%d to %c\n", i, i);
    }

//    while (1){
//        znak = 7;
//        printf("%d to %c\n\n", znak, znak);
//    }

    return 0;
}