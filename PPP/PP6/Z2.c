#include <stdio.h>
#include <stdlib.h>

void print_tab_all(int size,int a[][size], int x){
//bedzie wypisywała tablice dwuwymiarowa o dowolnie dlugich wierszach
//dlugosc wiersza size - musi byc w nagłówku przed ( nie koniecznie bezpośrednio)
//deklaracją tablicy, k torej wiersze sa dlugie na size
//ilosc wierszy x moze byc w dowolnym miejscy
    int i, j;
    for (i = 0; i < x; i++){
        for (j = 0; j < size; j++)
            printf ("%3d", a[i][j]);
        printf ("\n");
    }
    printf ("\n");
}

void print_tab_dyn(int size,int **a, int x){
//bedzie wypisywała tablice dwuwymiarowa o dowolnie dlugich wierszach
//dlugosc wiersza size - musi byc w nagłówku przed ( nie koniecznie bezpośrednio)
//deklaracją tablicy, k torej wiersze sa dlugie na size
//ilosc wierszy x moze byc w dowolnym miejscy
    int i, j;
    for (i = 0; i < x; i++){
        for (j = 0; j < size; j++)
            printf ("%3d", a[i][j]);
        printf ("\n");
    }
    printf ("\n");
}

void swap(int * a, int * b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap_tab(int * a, int * b, int size){
    for ( int i = 0; i < size; i++) {
        swap(&a[i], &b[i]);
    }
//procedura wymieniająca zawartość tablic a i b (o tym samym rozmiarze) przy użyciu procedury swap
// wymieniamy zawartość elementu a[i] z zawartością elementu b[i]
}

void swap_row(int n, int (*a)[n], int x, int y){
    swap_tab(a[x], a[y], n);
// procedura wymieniająca  wiersz x z wierszem y - wiersze mają tę samą długość
// przy użyciu procedury swap_tab
}

void swap_row_dynamic(int n, int **a, int x, int y){
    swap_tab(a[x], a[y], n);
// procedura wymieniająca  wiersz x z wierszem y - wiersze mają tę samą długość
// przy użyciu procedury swap_tab
}


int main() {
    int tab_1[4][5] = {1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4};
    print_tab_all(5,tab_1,4);
    swap_row(5, tab_1, 1 ,3);
    print_tab_all(5,tab_1,4);
    //- wymiana wiersza 1 z 3 przy użyciu procedury swap_raw

    int tab_11[4][5] = {1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4};
    print_tab_all(5,tab_11,4);
    swap_row(5, tab_11, 0 ,3);
    print_tab_all(5,tab_11,4);
    //- wymiana wiersza 0 z 3 przy użyciu procedury swap_tab

    int tab_2 [5][2] = {1,1,2,2,3,3,4,4,5,5};
    print_tab_all(2,tab_2,5);
    swap_row(2, tab_2, 0 ,2);
    print_tab_all(2,tab_2,5);
    //- wymiana wiersza 0 z 2 przy użyciu procedury swap_raw

    int tab_22 [5][2] = {1,1,2,2,3,3,4,4,5,5};
    print_tab_all(2,tab_22,5);
    swap_tab(tab_22[1], tab_22[2], 2);
    print_tab_all(2,tab_22,5);
    //- wymiana wiersza 1 z 2 przy użyciu procedury swap_tab

    // dla tablicy tab_3 - wymiana wiersza 1 z 5

    int **tab_3 = malloc( 6*3*sizeof(int));

    for(int i = 0; i < 6; i++)
        tab_3[i] = malloc(3 * sizeof(int));

    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 3; j++)
            tab_3[i][j]  =  rand() % 21;

    print_tab_dyn(3,tab_3,6);
    swap_row_dynamic(3, tab_3, 1 , 5);
    print_tab_dyn(3,tab_3,6);

    // dla tablicy tab_33 - wymiana wiersza 2 z 4

    int **tab_33= malloc( 6*3*sizeof(int));

    tab_33[0] = malloc(3*sizeof(int));
    for(int i = 1; i < 6; i++)
        tab_33[i] = tab_33[i-1]+3;

    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 3; j++)
            tab_33[i][j]  =  rand() % 21;

    print_tab_dyn(3,tab_33,6);
    swap_row_dynamic(3, tab_33, 2 , 4);
    print_tab_dyn(3,tab_33,6);
    return 0;
}
