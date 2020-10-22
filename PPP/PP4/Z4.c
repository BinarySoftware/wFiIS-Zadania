#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int floatNotEq(float a, float b){
    float f = fabs(a-b);
    return (f > 0.01);
}

float * mergeArrays(float arr1[], float arr2[], int n1, int n2){
    float * wynik = malloc(sizeof(float));
    if (!wynik){
        printf("Brak pamieci\n");
        exit(-1);
    }
    int i = 0, j = 0, k = 1, sizeWynik = 1;
    wynik[0] = arr1[0];
    while (i<n1 && j<n2){
        if (arr1[i] < arr2[j]){
            if(floatNotEq(wynik[k-1],arr1[i])){
                sizeWynik++;
                wynik = realloc(wynik, sizeWynik*sizeof(float));
                if (!wynik){
                    printf("Brak pamieci\n");
                    exit(-1);
                }
                wynik[k++] = arr1[i++];
            } else {
                i++;
            }
        } else {
            if(floatNotEq(wynik[k-1],arr2[j])){
                sizeWynik++;
                wynik = realloc(wynik, sizeWynik*sizeof(float));
                if (!wynik){
                    printf("Brak pamieci\n");
                    exit(-1);
                }
                wynik[k++] = arr2[j++];
            }else {
                j++;
            }
        }
    }

    while (i < n1) {
        if(floatNotEq(wynik[k-1],arr1[i])) {
            sizeWynik++;
            wynik = realloc(wynik, sizeWynik * sizeof(float));
            if (!wynik){
                printf("Brak pamieci\n");
                exit(-1);
            }
            wynik[k++] = arr1[i++];
        } else {
            i++;
        }
    }

    while (j < n2) {
        if(floatNotEq(wynik[k-1],arr2[j])) {
            sizeWynik++;
            wynik = realloc(wynik, sizeWynik * sizeof(float));
            if (!wynik){
                printf("Brak pamieci\n");
                exit(-1);
            }
            wynik[k++] = arr2[j++];
        }else {
            j++;
        }
    }
    return wynik;
}

int main() {
    float arg_1[] = {1.0, 1.2, 1.2,
                     1.5,1.5, 1.5,
                     1.6, 1.6, 1.8, 1.9};
    float arg_2[] = {1.0, 1.1, 1.1,
                     1.2, 1.4, 1.5,
                     1.6, 1.6, 1.8,
                     1.8, 1.8, 1.9,
                     1.9, 2.0, 2.0};
    int n1 = sizeof(arg_1)/ sizeof(float);
    int n2 = sizeof(arg_2)/ sizeof(float);
    float * wynik = mergeArrays(arg_1,arg_2,n1,n2);
    for (int i = 0; i < n1+n2; ++i) {
        if (wynik[i]<wynik[i-1]){
            //Doszlismy do konca tablicy
            break;
        }
        printf("%.2f, ",wynik[i]);
    }
    free(wynik);
    return 0;
}
