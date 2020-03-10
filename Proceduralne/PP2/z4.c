//
// Created by Maciej Mikołajek on 03/03/2020.
//

#include <stdio.h>
#include <stdlib.h>

void swap(float *a, float *b){
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(float * A, int p, int r){
    float x = A[p];
    int i = p - 1;
    int j = r + 1;
    while (1) {
        do {
            j =  j - 1;
        } while (A[j] > x);
        do {
            i = i + 1;
        } while (A[i] < x);
        if (i < j){
            swap (A+i,A+j);
        } else {
            return j;
        }
    }
}

void Quicksort(float * A, int p, int r){
    if (p < r) {
        int q = Partition(A, p, r);
        Quicksort(A,p,q);
        Quicksort(A,q+1,r);
    }
}

float float_rand(float min, float max ){
    float scale = rand() / (float) RAND_MAX;
    return min + scale * ( max - min );
}

// Pomocnik do drukowania tablicy
void print_tab(float *arr, int size){
    int i;
    for (i=0; i < size; i++){
        printf("%0.2f, ", arr[i]);
    }
    printf("\n");
}

int main(){
    int rozmiar = 10;
    float tab[rozmiar];
    for(int i = 0; i < rozmiar; i++){
        tab[i] = float_rand(-1.5,5.5);
    }
    printf("Tablica przed posortowaniem:\n");
    print_tab(tab, rozmiar);
    Quicksort(tab, 0, rozmiar);
    printf("Tablica po posortowaniu:\n");
    print_tab(tab, rozmiar);
}