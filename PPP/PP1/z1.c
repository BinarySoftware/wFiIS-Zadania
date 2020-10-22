#include <stdio.h>
#include <stdlib.h>
#define N 10

int suma_rek(const int * pocz, const int * kon);

int rand_int(int a, int b) {
    return (a + rand()%(b-a+1));
}

int main(void){
    int tab[N];
    int * p = NULL;

    for (p = tab; p < tab + N; p++){
        *p = rand_int(7,35);
        printf("tab[%d] = %d\n", p - tab,*p);
    }

    printf("\n");

    int su = suma_rek(tab, p-1);
    printf("su=%d\n",su);
    return 0;
}

int suma_rek(const int * pocz, const int * kon) {
    if (pocz < kon)
        return *pocz + suma_rek(pocz+1, kon);
    else
        return *kon;
}
