//
// Created by Maciej Mikołajek on 04/12/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
}

int rand10(){
    return i_rand(0, 9);
}

int main(void){
    srand(time(0));
    int a[50];
    int b[51];
    b[0] = 0;

    //Losowanie cyfr 0..9 do a i b
    for(int i = 0; i<50; i++){
        a[i] = rand10();
        b[i+1] = rand10(); // przesuniecie o 1 aby zostawic miejsce na najwiekszą cyfrę
    }

    //Drukowanie wylosowanych liczb
    printf("  ");
    for(int i = 0; i<50; i++){
        printf("%d", a[i]);
    }
    printf("\n+ ");
    for(int i = 1; i<51; i++){
        printf("%d", b[i]);
    }
    printf("\n");
    for(int i = 0; i<52; i++){
        printf("-");
    }
    printf("\n ");

    //Dodawanie
    for(int i = 49; i >= 0; i--){
        b[i+1] = b[i+1] + a[i];
        if(b[i+1]>=10){
            b[i+1] = b[i+1]-10;
            b[i] = b[i] + 1;
        }
    }
    for(int i = 0; i<51; i++){
        printf("%d", b[i]);
    }
}