//
// Created by Maciej Mikołajek on 03/03/2020.
//

#include <stdio.h>
#include <math.h>

void sitoErastotenesa(int n);

int main() {
    sitoErastotenesa(100001);
    sitoErastotenesa(100000);
    sitoErastotenesa(1000);
    return 0;
}

void sitoErastotenesa(int n) {
    if (n >= 100000) {
        printf("Zbyt duże n: %d >= 100000\n", n);
    } else {
        int i;
        int j;
        int till = floor(sqrt(n));

        int t[n];
        for (i=1; i <= n; i++) {
            t[i]=1;
        }

        for (i=2; i <= till; i++){
            if (t[i] != 0){
                j = i+i;
                while (j <= n){
                    t[j] = 0;
                    j += i;
                }
            }
        }
        printf("Liczby pierwsze z zakresu od 1 do %d:\n", n);
        for (i=2; i <= n; i++) {
            if (t[i] != 0) {
                printf("%d, ",i);
            }
        }
    }
}