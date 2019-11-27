//
// Created by Maciej Mikołajek on 27/11/2019.
//
#include <stdio.h>

void wiersz(char litera, char i);
char pobierzLitere(void);

int main(void) {
    char litera = pobierzLitere();

    for(char i='A'; i<=litera; i++){
        wiersz(litera, i);
    }
}

char pobierzLitere(void) {
    char litera;
    do {
        printf("Podaj litere z przedziału <A,Z> :");
        scanf("%c", &litera);
        while(getchar()!='\n');
    } while (litera < 'A' || litera > 'Z');
    return litera;
}

void wiersz(char litera, char i) {
    // Wypisuje spacje przed literami
    for(int j='A'; j<=i; j++){
        printf(" ");
    }
    // Wypisuje litery z lewej strony piramidy
    for(int j=litera; j>=i; j--){
        printf("%c",j);
    }
    // Wypisuje litery z prawej strony piramidy
    for(int j=i+1; j<=litera; j++){
        printf("%c",j);
    }
    printf("\n");
}
