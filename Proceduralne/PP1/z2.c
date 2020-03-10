#include <stdio.h>
#define N 5
void zamiana(float * x , float * y);

void odwroc(float * pocz, float * kon);

void wymien_tablice(float * pocz1, float * pocz2, float * kon);

int main(void){
    float x = 1.23, y = 4.56;
    printf("x = %f, y = %f\n",x,y);
    zamiana(&x,&y);
    printf("x = %f, y = %f\n",x,y);
    float tab[N] = {1.3,2.4,3.5,4.6,5.7};
    printf("\n");
    for (int i = 0; i<N;i++){
        printf("tab[%d] = %f\n", i, tab[i]);
    }
    odwroc(tab,tab+N-1);
    printf("ODWRACANIE ELEMENTOW W TABLICY\n");
    for (int i = 0; i<N;i++){
        printf("tab[%d] = %f\n", i, tab[i]);
    }

    float tab2[N] = {1.5,3.455,6.433,2.44,1.232};
    printf("ZAMIANA TABLIC\n");
    for (int i = 0; i<N;i++){
        printf("tab1[%d] = %f\t tab2[%d] = %f\n", i, tab[i], i, tab2[i]);
    }
    printf("\n");
    wymien_tablice(tab,tab2,tab+N);
    for (int i = 0; i<N;i++){
        printf("tab1[%d] = %f\t tab2[%d] = %f\n", i, tab[i], i, tab2[i]);
    }
    return 0;
}

void zamiana(float * x, float * y) {
    float z = *x;
    *x = *y;
    *y = z;
}

void odwroc(float * pocz, float * kon){
    for (int i = 0; i <= (kon-pocz)/2; i++){
        zamiana(pocz+i,kon-i);
    }
}

void wymien_tablice(float * pocz1, float * pocz2, float * kon) {
    for (int i = 0; i < (kon - pocz1); i++) {
        zamiana(pocz1 + i, pocz2 + i);
    }
}