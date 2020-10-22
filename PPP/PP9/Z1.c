//
// Created by Maciej Mikołajek on 28/04/2020.
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


/// KOMPARATORY
int char_cmp(const void * a, const void * b){
    int x = *(char*) a;
    int y = *(char*) b;

    int xz = x >= 'a' ? x-32 : x;
    int yz = y >= 'a' ? y-32 : y;

    int znak = xz-yz;
    if(znak != 0) {
        return -(x - y);
    } else {
        return znak;
    }
}

int tabchars_cmp(const void * a, const void * b){
    return strcmp(a, b);
}

/// TAB FUNCS
void printTabCharArray(int x, int y, char tab[x][y]){
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            printf("%c", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void generateRandomStrings(int x, int y, char tab[x][y]){
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            int randomNbr = rand() % 52;
            if(randomNbr < 26) {
                tab[i][j] = 'A' + randomNbr;
            } else {
                tab[i][j] = 'a' + (randomNbr - 26);
            }
        }
    }
}

void sortCharsInString(int x, int y, char tab[x][y]){
    for(int i=0; i<x; i++){
        qsort(tab[i], y, sizeof(char), char_cmp);
    }
}

void sortStrings(int x, int y, char tab[x][y]){
    qsort(tab,x,y, tabchars_cmp);
}

/// MAIN
int main(void){
    srand(time(NULL));
    char tab[20][15];

    generateRandomStrings(20, 15, tab);

    printf("Wygenerowane łańcuchy:\n");
    printTabCharArray(20, 15, tab);

    sortCharsInString(20, 15, tab);
    printf("Posortowany każdy łańcuch:\n");
    printTabCharArray(20, 15, tab);

    sortStrings(20, 15, tab);
    printf("Posortowana tablica łańcuchów:\n");
    printTabCharArray(20, 15, tab);

    return 0;
}
