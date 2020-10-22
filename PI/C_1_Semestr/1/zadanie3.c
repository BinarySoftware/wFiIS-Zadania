//
// Created by Maciej Mikołajek on 20/11/2019.
//

#include <stdio.h>

int main(void){
    float a;
    double b;
    long double c;
    int calkowita;

    a = -1.8e-10;
    printf("Pojedyncza precyzja: %f = %.10f = %.20f\n", a, a, a);

    b = -1.8e-10;
    printf("Podwojna precyzja: %f = %.10f = %.20f\n", b, b, b);

    c = -1.8e-10;
    printf("long double: %Lf = %.10Lf = %.20Lf\n\n", c, c, c);

    printf("Notacja wykladnicza: %e = %.2e = %Le\n\n", a, b, c);

    b = 5/3;
    printf("5 dzielone przez 3 = %f\n\n", b);

    b = 5.0/3.0;
    printf("5 dzielone przez 3 = %f\n\n", b);

    printf("Wpisz liczbe rzeczywista: ");
    scanf("%f", &a);
    printf("Wpisales: %f.\n", a);

    printf("Wpisz liczbe calkowita: ");
    scanf("%d", &calkowita);
    printf("Wpisales: %d.\n", calkowita);

    return 0;
}