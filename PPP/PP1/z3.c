#include <stdio.h>
#include <math.h>
#define N 5

float suma(float * t, int n);

int main(void){
    float tab[N] = {1.2,2.3,3.4,4.5,5.6};
    suma(tab,N);
}

float suma(float * t, int n){
    float sum = 0;
    for(int i = 0; i < n; i++){
        sum += *(t+i);
    }
    float avg = sum/((float)n);
    float min_dev = fabs(avg-*t);
    float max_dev = min_dev;
    for(int i = 0; i < n; i++) {
        float dev = fabs(avg-*(t+i));
        if (dev < min_dev)
            min_dev = dev;
        else if (dev > max_dev)
            max_dev = dev;
    }
    printf("suma: %f, avg: %f, min_dev: %f, max_dev: %f", sum, avg, min_dev, max_dev);
    return sum;
}
