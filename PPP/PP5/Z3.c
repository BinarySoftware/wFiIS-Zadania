#include <stdio.h>
#include <stdlib.h>

void print_tab(int a[][4], int x){
    int i, j;
    for (i = 0; i < x; i++){
        for (j = 0; j < 4; j++)
            printf ("%3d", a[i][j]);
        printf ("\n");
    }
}

void wypisz_i (int *poczatek, int *koniec) {
    while (poczatek < koniec)
        printf ("%4d", *poczatek++);
    printf ("\n");
}

int ** mn_tab_1(int a[][3], int b[][4], int x){
    int ** wynik = malloc(x * 4 * sizeof(int));
    if (wynik == NULL){
        printf("Blad alokacji pamieci");
        exit(0);
    }

    for (int i = 0; i < x; i++){
        wynik[i] = calloc(4, sizeof(int));
        if (wynik[i] == NULL){
            printf("Blad alokacji pamieci");
            exit(0);
        }
    }

    for (int i = 0; i < x; i++){
        for (int j = 0; j < 4; j++){
            wynik[i][j] = 0;
            for(int k = 0; k < 3; k++){
                wynik[i][j] = wynik[i][j] + a[i][k] * b[k][j];
            }
        }
    }
    return wynik;
}

int main() {
    int t_A [2][3] = {{1,2,3},
                      {4,5,6}};
    int t_B [3][4] = {{1,1,1,1},
                      {1,1,1,1},
                      {1,1,1,1}};

    int ** t_C = mn_tab_1 (t_A, t_B, 2);
    for (int i = 0; i < 2; i++) {
        wypisz_i(t_C[i], t_C[i]+4);
    }

    printf("\n");
    print_tab((int(*)[4]) *t_C, 2);
    return 0;
}
