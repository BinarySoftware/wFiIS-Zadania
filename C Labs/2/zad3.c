//
// Created by Maciej Mikołajek on 27/11/2019.
//
#include <stdio.h>

void wiersz(int cyfra, int i);

int main(void){
    int cyfra;
    do{
        printf("Podaj cyfre z przedziału <0,9> :");
        scanf("%d", &cyfra);
    }while(cyfra<0 || cyfra>9);

    for(int i=0; i<=cyfra; i++){
        wiersz(cyfra, i);
    }
}

void wiersz(int cyfra, int i) {
    // Wypisuje spacje przed cyframi
    for(int j=1; j<=i; j++){
        printf(" ");
    }
    // Wypisuje cyfry
    for(int j=cyfra; j>=i; j--){
        printf("%d",j);
    }
    printf("\n");
}
