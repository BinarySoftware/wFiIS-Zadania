#include <stdio.h>
#include <stdlib.h>


void wypisz_i (int *poczatek, int *koniec) {
    while (poczatek < koniec)
        printf ("%4d", *poczatek++);
    printf ("\n");
}

//void proc_1(int rozmiar, int *array){
//    int pierwszyElement = array[0];
//
//    for(int i=0; i < rozmiar - 1; i++){
//        array[i] = array[i + 1];
//    }
//
//    array[rozmiar - 1] = pierwszyElement;
//}
//
//void proc_l(int rozmiar, int array[rozmiar], int k){
//    for(int i=0; i < k; i++){
//        proc_1(rozmiar, array);
//    }
//}

void proc_1(int *pierwszy, int *ostatni){
    int pierwszyElement = *pierwszy;

    for(int i=0; i < ostatni-pierwszy; i++){
        *(pierwszy+i) = *(pierwszy+i+1);
    }

    *ostatni = pierwszyElement;
}

void proc_l(int *pierwszy, int *ostatni, int k){
    for(int i=0; i < k; i++){
        proc_1(pierwszy, ostatni);
    }
}

int main() {
    printf("TABLICA 1\n");
    int tab_1[5] = {1,2,3,4,5};
//    wypisz_i(&tab_1[0], &tab_1[5]);
    proc_l(tab_1, tab_1+4, 3);
    printf("\n");
    wypisz_i(&tab_1[0], &tab_1[5]);


    printf("TABLICA 2\n");
    int tab_2[4][2] = {{10,11},{12,13},{14,15},{16,17}};
//    printf("\n");
//    for (int i = 0; i < 4; i++) {
//        wypisz_i(&tab_2[i][0], &tab_2[i][2]);
//    }
    proc_l(&tab_2[0][0], &tab_2[3][1], 3);
    printf("\n");
    for (int i = 0; i < 4; i++) {
        wypisz_i(&tab_2[i][0], &tab_2[i][2]);
    }


    // Pani Doktor,
    // Nie wiem co się tutaj dzieje, ale poniższy kod - a debugowałem go chwilę
    // alokuje tablicę o rozmiarze 5X4 a nie 5X3, co powoduje że :
    // Tablica wygląda:
    //  0   1   2   0
    //  3   4   5   0
    //  6   7   8   0
    //  9  10  11   0
    // 12  13  14   0
    // Ma jedną dodatkową kolumnę z zerami co psuje procedurę proc_l.
    // natomiast poniżej - tab_3_2 - jest podobna tablica, tyle że traktuje ją
    // troche jak tablice 1D, a nie 2D, dzieki czemu nie mam problemu z kolumną
    // wypełnioną zerami.

    printf("TABLICA 3 - wersja 1\n");
    int **tab_3 = malloc(5 * 3 * sizeof(int));
    for (int i=0; i<5; i++)
        tab_3[i] = malloc(3 * sizeof(int));

    for (int i = 0; i <  5; i++)
        for (int j = 0; j < 3; j++)
            tab_3[i][j] = i*3 + j;

    printf("\n");
    for (int i = 0; i < 5; i++) {
        wypisz_i(&tab_3[i][0], &tab_3[i][3]);
    }
    proc_l(&tab_3[0][0], &tab_3[4][2], 1);
    printf("\n");
    for (int i = 0; i < 5; i++) {
        wypisz_i(&tab_3[i][0], &tab_3[i][3]);
    }


    printf("TABLICA 3 - wersja 2\n");
    int **tab_3_2 = malloc(5 * sizeof(int*));
    for (int i=0; i<5; i++)
        tab_3_2[i] = malloc(3 * sizeof(int));

    for (int i = 0; i <  3*5; i++)
        for (int j = 0; j < 3; j++)
            *(&tab_3_2[0][0]+i) = i;

    printf("\n");
    wypisz_i(&tab_3_2[0][0], &tab_3_2[0][0]+3*5);
    proc_l(&tab_3_2[0][0], &tab_3_2[4][2], 1);
    printf("\n");
    wypisz_i(&tab_3_2[0][0], &tab_3_2[0][0]+3*5);

    return 0;
}