//
// Created by Maciej Mikołajek on 20/11/2019.
//

#include <stdio.h>
#include <math.h>

int main(void){
    int a;
    float b;

    printf("\n");

    for(a = 1; a < 3.05; a++){
        if(a == 2){
            printf("\tTeraz a to dwojka: a = %d\n", a);
        }
        else{
            printf("a = %d, czyli nie jest dwojka\n", a);
        }
    }

    printf("\n\n");

    for(b = 1.0; b < 3.05; b += 0.2){
        float diff = fabs(b-2.0);
        printf("Roznica: d = %g\n", diff);

        // Pamiętaj, żeby liczb zmiennoprzecinkowych nie porównywać przy pomocy operatora "=="

        diff<1.0e-6 ? printf("\tTeraz b to dwojka: b = %g\n", b) : printf("b = %g, czyli nie jest dwojka\n", b);

//        if(diff<1.0e-6){
//            printf("\tTeraz b to dwojka: b = %g\n", b);
//        }
//        else{
//            printf("b = %g, czyli nie jest dwojka\n", b);
//        }
    }

    printf("\n");

    {
        // precyzja floata, dokladnosc przeliczania na binarny, mantysa etc.
        float a = 1.f;
        float b = 5.e-8;
        printf("a = %g, b = %g\n", a, b);
        printf("a + b + b = %g = %.25f\n", a + b + b, a + b + b);
        printf("b + b + a = %g = %.25f\n", b + b + a, b + b + a);
    }

    return 0;
}