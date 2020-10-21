//
// Created by Maciej Mikołajek on 20/11/2019.
//

#include <stdio.h>

int pow(int x, int n);

int main(void){
    int i,k;
    for (i = 0; i < 5; ++i) {
        k = pow(i,2);
        printf("%d\n",k);
    }
    printf("KONIEC: %d\n",i);
    return 0;
}

int pow(int x, int n){
    int result = 1;
    for (int i = 0; i < n; ++i) {
        result = result * x;
    }
    return result;
}