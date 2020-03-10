//
// Created by Maciej Mikołajek on 03/03/2020.
//

#include <stdio.h>
#define R sizeof(int)*8+1

void do_binar(int n, char * wsk);

unsigned bity(int x, int p, int n);

// Pomocnik do drukowania tablicy
void print_tab(char *arr, int size){
    int i;
    for (i=0; i < size; i++){
        printf("%c", arr[i]);
    }
    printf("\n");
}

int main (){
    unsigned wynik;
    unsigned liczba = 18; // 10010
    char tab[R];
    for(int i=0; i<R; i++){
        // inicjalizacja tablicy znakami ktore sie nie wyswietlaja,
        // aby nie dostac jej wypelnionej randomowymi liczbami
        tab[i] = 1;
    }

    do_binar(liczba, tab);
    printf("liczba : %s\n", tab);

    int p = 1;
    int n = 3;
    wynik = bity(liczba, p, n); // 3 bity od pozycji 1, czyli: 1 001 0
    char tab2[R];
    for(int i=0; i<R; i++){
        tab2[i] = 1;
        if (i >= R-p-n  && i <= R-p){
            tab2[i] = 48;
            // trick aby moc wyswietlic zera przed 1. jedynka
        }
    }

    do_binar(wynik, tab2);
    printf("%d bity od pozycji %d, czyli: %s\n", n, p, tab2);
    return 0;
}

void do_binar(int n, char * wsk){
    int i = 1;
    while (n > 0) {
        ++i;
        int bit = n&01;
        *(wsk+(R-i)) = (48 + bit); // ASCII(48) : 0
        n >>= 1;
    }
    *(wsk+(R-1)) = '\0';
}

unsigned bity(int x, int p, int n){
    int t = x >> p;
    int k = x>>(p+n)<<n;
    return t^k;
}