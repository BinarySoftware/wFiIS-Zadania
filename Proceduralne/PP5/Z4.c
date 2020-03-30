#include <stdio.h>
#include <stdlib.h>

#define columns 4
int** create_table(int *);

void wypisz_i (int *poczatek, int *koniec) {
    while (poczatek < koniec)
        printf ("%4d", *poczatek++);
    printf ("\n");
}

int main() {
    int length = 0;
    int * input = calloc(length,sizeof(int));
    int current = 1;
    while (current != 0) {
        printf("Podaj liczbe: ");
        scanf("%d", &current);
        length++;
        input = realloc(input, length*sizeof(int));
        input[length-1] = current;
    }
    int ** tab = create_table(input);

    int i = 0;
    while (tab[i] != 0){
        wypisz_i(tab[i], tab[i]+4);
        i++;
    }
    return 0;
}

int ** create_table(int * a){
    int rows = 1;

    int ** array_1 = malloc(rows*columns*sizeof(int));
    if (array_1 == NULL){
        printf("Blad alokacji pamieci");
        exit(0);
    }
    array_1[0] = calloc(columns, sizeof(int));
    if (array_1[0] == NULL){
        printf("Blad alokacji pamieci");
        exit(0);
    }

    int i = 0;
    do {
        if (i%columns == 0 && i != 0){
            rows++;
            array_1 = realloc(array_1,rows*columns*sizeof(int));
            array_1[i/4] = calloc(columns, sizeof(int));
            if (array_1[i/4] == NULL){
                printf("Blad alokacji pamieci");
                exit(0);
            }
        }
        array_1[i/4][i%4] = a[i];
        i++;
    } while (a[i] != 0);
    return array_1;
}