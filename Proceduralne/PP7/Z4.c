#include <stdio.h>

int add2(int * a, int * b){
    return *a+*b;
}

int comp2(int * a, int * b){
    return *a-*b;
}

int add2_or_comp2 (int * a, int * b, int F(int * , int *)){
    return F(a,b);
}

int main() {
    int a = 34;
    int b = 52;

    int suma = add2_or_comp2(&a, &b, add2);
    int roznica = add2_or_comp2(&a, &b, comp2);

    printf("a = %d, b = %d, suma = %d, roznica = %d\n", a, b, suma, roznica);
    return 0;
}
