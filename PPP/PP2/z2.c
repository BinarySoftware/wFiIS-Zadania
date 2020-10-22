//
// Created by Maciej Mikołajek on 03/03/2020.
//

#include <stdio.h>
#include <assert.h>

#define ILOSC_ELEMENTOW(x)  (sizeof(x) / sizeof((x)[0]))

void swap(int *a, int *b);
int * find_max_wsk (int *, int *);
void sort (int *tab, int n);

// Pomocnik do drukowania tablicy
void print_tab(int *arr, int size){
    int i;
    for (i=0; i < size; i++){
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main() {
    int tab_A[] = {3,5,33,1,7,
                   9,55,1,11,22,
                   12,6,8,4,44,
                   6,42,2,8,26,
                   64,80,16};

    int n = ILOSC_ELEMENTOW(tab_A);
    int *max_wsk = find_max_wsk(tab_A, tab_A+(n-1));
    assert(*max_wsk == 80);
    printf("Najwiekszy element: %d, adres: %ld\n", *max_wsk, max_wsk);

    printf("Tablica przed posortowaniem:\n");
    print_tab(tab_A, n);

    printf("Nieparzyste posortowane:\n");
    sort(tab_A, 9);
    print_tab(tab_A, 9);

    printf("Parzyste posortowane:\n");
    sort(tab_A+9, n-9);
    print_tab(tab_A+9, n-9);

    sort(tab_A, n);
    printf("Tablica po posortowaniu:\n");
    print_tab(tab_A, n);
    return 0;
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int * find_max_wsk (int * pocz, int * kon){
    int *max_temp = pocz;
    int *iter = pocz;
    while (iter <= kon){
        if (*iter > *max_temp) {
            max_temp = iter;
        }
        iter++;
    }
    return max_temp;
}

void sort (int *tab, int n){
    int i;
    for (i = 0; i < n; i++){
        int *max_wsk = find_max_wsk(tab+i, tab+(n-1));
        swap(tab+i, max_wsk);
    }
}