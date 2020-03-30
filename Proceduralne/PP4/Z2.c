#include <stdio.h>
#include <stdlib.h>

float * avg_two(float * a, float * b){
    float * avg = malloc(sizeof(float));
    if (!avg){
        printf("Brak pamieci\n");
        exit(-1);
    }
    *avg = *a / *b;
    return avg;
}

int main() {
    float a = 2.2;
    float b = 1.5;
    float *c = avg_two(&a, &b);
    printf("%f %ld ", *c, c);
    a = 2.0;
    b = 1.0;
    float *d = avg_two(&a, &b);
    printf("%f %ld ", *d, d);
    free(c);
    free(d);
    return 0;
}
