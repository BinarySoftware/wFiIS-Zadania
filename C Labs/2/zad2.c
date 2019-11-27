//
// Created by Maciej Mikołajek on 27/11/2019.
//
#include <stdio.h>

double element(int n);

int main(void){
    double s = 0;
    int i = 0;
    double eps = 1e-8;
    while(i>=0){
        double res = element(i+1);
        s += res;
        if(res<eps){
            break;
        }
        i++;
    }
    printf("\nsuma %d elementow: %.4f",i,s);
    return 0;
}

double element(int n){
    double nf = n;
    double pow = nf*nf;
    double res = 1.0/pow;
    return res;
}
