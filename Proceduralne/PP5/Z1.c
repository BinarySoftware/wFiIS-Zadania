#include <stdio.h>
#include <stdlib.h>

#define rows 4
#define columns 5

void wypisz_i (int *poczatek, int *koniec) {
    while (poczatek < koniec)
        printf ("%4d", *poczatek++);
    printf ("\n");
}

int main(void){
    // Array 1
    int ** array_1 = malloc(rows*columns*sizeof(int));
    if (array_1 == NULL){
        printf("Blad alokacji pamieci");
        exit(0);
    } else {
        for (int i = 0; i < rows; i++){
            array_1[i] = calloc(columns, sizeof(int));
            if (array_1[i] == NULL){
                printf("Blad alokacji pamieci");
                exit(0);
            }
        }

        printf("array 1: \n");
        for (int i = 0; i < rows; i++){
            wypisz_i(array_1[i], array_1[i]+columns);
        }
        free(array_1);
    }
    printf("\n");

    // Array 2
    int ** array_2 = malloc(rows*columns*sizeof(int));
    if (array_2 == NULL){
        printf("Blad alokacji pamieci");
        exit(0);
    } else {
        int * elementy = calloc(rows * columns, sizeof(int));
        if (elementy == NULL){
            free(array_2);
            printf("Blad alokacji pamieci");
            exit(0);
        } else {
            for (int i = 0; i < rows; i++){
                array_2[i] = elementy + i * columns;
            }
            printf("array 2:\n");
            wypisz_i(array_2[0], array_2[0] + rows * columns);
            free(array_2);
            free(elementy);
        }
    }
    printf("\n");

    // Array 3
    int (*array_3)[columns]=calloc(rows*columns, sizeof(int));
    if (array_3 == NULL){
        printf("Blad alokacji pamieci");
        exit(0);
    } else {
        printf("array 3:\n");
        wypisz_i(array_3[0], array_3[0] + rows * columns);
        free(array_3);
    }

    return 0;
}
