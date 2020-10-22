//
// Created by Maciej Mikołajek on 20/11/2019.
//

#include <stdio.h>
#include <limits.h>

int main(void){
    int i1 = -100, i2 = -200;
    int i3;

    short s1;
    short int s2;

    long l1;
    long int l2;

    long long L1;
    long long int L2;

    unsigned u1;
    unsigned int u2;

    i3 = 2*i2-i1;
    printf("Przykladowe liczby calkowite: %d, %d, %d oraz %d, %d.\n\n", i1, i2, i3, i1/i2, -600);
    i3 = 64;
    printf("Dziesietne %d to w systemie osemkowym %o, a w systemie szesnastkowym: %x.\n", i3, i3, i3);
    printf("Dziesietne %d to w systemie osemkowym %#o, a w systemie szesnastkowym: %#x.\n\n", i3, i3, i3);

    s1 = 32767;
    s2 = s1+1;
    printf("s1+1 = %d+1 = %d\n\n", s1, s2);

    printf("Zakres liczb typu int: od %d do %d.\n", INT_MIN, INT_MAX);
    printf("Zakres liczb typu short int: od %hd do %hd.\n", SHRT_MIN, SHRT_MAX);
    printf("Zakres liczb typu long int: od %ld do %ld.\n", LONG_MIN, LONG_MAX);
    printf("Zakres liczb typu long long int: od %lld do %lld.\n", LLONG_MIN, LLONG_MAX);

    printf("Zakres liczb typu unsigned int: od %d do %d.\n", 0, UINT_MAX);
    printf("Zakres liczb typu unsigned int: od %u do %u.\n", 0, UINT_MAX);

    return 0;
}