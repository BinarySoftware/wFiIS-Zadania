//
// Created by Maciej Mikołajek on 04/12/2019.
//

#include <stdio.h>

int main(void){
    int primes[1001];
    for(int i = 0; i < 1001 ;i++){
        primes[i] = -1;
    }
    for(int i=2; i<= 1000;i++){
        int isPrime = 1;
        for(int j=2; j<i;j++){
            int m = i%j;
            if(m == 0) {
                isPrime = 0;
            }
        }
        if(isPrime == 1){
            primes[i] = i;
        }
    }
    for(int i = 0; i < 1001 ;i++){
        if(primes[i] != -1){
            printf("%d ", primes[i]);
        }
    }
    return 0;
}