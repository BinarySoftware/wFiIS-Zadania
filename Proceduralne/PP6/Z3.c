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
    int tab_1[5] = {1,2,3,4,5};
    wypisz_i(&tab_1[0], &tab_1[5]);
    proc_l(tab_1, tab_1+4, 3);
    printf("\n");
    wypisz_i(&tab_1[0], &tab_1[5]);


    int tab_2[4][2] = {{10,11},{12,13},{14,15},{16,17}};
    printf("\n");
    for (int i = 0; i < 4; i++) {
        wypisz_i(&tab_2[i][0], &tab_2[i][2]);
    }
    proc_l(&tab_2[0][0], &tab_2[3][1], 3);
    printf("\n");
    for (int i = 0; i < 4; i++) {
        wypisz_i(&tab_2[i][0], &tab_2[i][2]);
    }


    int **tab_3 = malloc(5 * 3 * sizeof(int));
    for (int i=0; i<5; i++)
        tab_3[i] = calloc(3,sizeof(int));

    for (int i = 0; i <  5; i++)
        for (int j = 0; j < 3; j++)
            *(*(tab_3 + i) + j) = i*3 + j;

    printf("\n");
    for (int i = 0; i < 5; i++) {
        wypisz_i(&tab_3[i][0], &tab_3[i][3]);
    }
    proc_l(&tab_3[0][0], &tab_3[4][2], 1);
    // FIXME
    printf("\n");
    for (int i = 0; i < 5; i++) {
        wypisz_i(&tab_3[i][0], &tab_3[i][3]);
    }
    return 0;
}