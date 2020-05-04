#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct tab_tab{
    int *tab;
    int n;
};

int suma(int *t, int count){
    int i, s = 0;
    for(i = 0; i < count; i++){
        s += t[i];
    }
    return s;
}

int rand_int(int a, int b) {
    return (a + rand()%(b-a+1));
}


int main() {
    srand(time(0));
    int num[] = {3, 6, 4, 2};
    size_t count = sizeof(num)/sizeof(num[0]);

    struct tab_tab TAB[count];
    for (int i = 0; i<count; i++){
        int * tabInt = malloc(sizeof(int) * num[i]);
        for (int j = 0; j<num[i]; j++) {
            tabInt[j]= rand_int(2,7);
        }
        struct tab_tab tempTab = {tabInt, num[i]};
        TAB[i] = tempTab;
    }

    for (int i = 0; i<count; i++){
        for (int j = 0; j<TAB[i].n; j++) {
            printf("i=%d, j=%d, wartosc: %d\n", i, j, TAB[i].tab[j]);
        }
    }

    struct tab_tab minSum = TAB[0];
    for (int i = 1; i<count; i++){
        int sumMin = suma(minSum.tab, minSum.n);
        int sumaB = suma(TAB[i].tab, TAB[i].n);
        if (sumaB < sumMin){
            minSum = TAB[i];
        }
    }

    printf("TABLICA O MIN SUMIE:\n");
    for (int j = 0; j<minSum.n; j++) {
        printf("j=%d, wartosc: %d\n", j, minSum.tab[j]);
    }

    return 0;
}
