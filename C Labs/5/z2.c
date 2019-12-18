//
// Created by Maciej Mikołajek on 18/12/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float f_rand(float min, float max){
    float r = (float) rand()/RAND_MAX;
    return r*(max-min) + min;
}

void losujLiczbe(float *sum, float *il) {
    float elem = f_rand(0.5, 1.5);
    *sum += elem;
    *il *= elem;
}

void losujLiczby(int n, float *sum, float *il, float *avg){
    *sum = 0;
    *il = 1;
    *avg = 0;

    for(int i = 0; i < n; i++){
        losujLiczbe(sum, il);
    }
    *avg = *sum / n;
}

int main(void){
    unsigned int t = time(NULL);
    srand(t);

    int n;
    printf("Podaj ilosc liczb: ");
    scanf("%d", &n);

    float sum = 0;
    float iloczyn = 1;
    float avg = 0;

    losujLiczby(n, &sum, &iloczyn, &avg);
    printf("\nsuma: %7.6f", sum);
    printf("\niloczyn: %g", iloczyn);
    printf("\nsrednia: %7.6f", avg);
    return 0;
}
