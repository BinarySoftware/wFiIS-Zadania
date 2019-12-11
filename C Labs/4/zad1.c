//
// Created by Maciej Mikołajek on 11/12/2019.
//

#include <stdio.h>

float suma(float a, float b);
float roznica(float a, float b);
float iloczyn(float a, float b);
float iloraz(float a, float b);

int main() {
    float a;
    float b;
    char opr;
    float s;

    printf("Wpisz operacje do obliczenia: ");
    scanf("%f%c%f", &a,&opr,&b);
    while (getchar()!='\n')
    printf("\n");

    switch (opr){
        case '+' :
            s = suma(a,b);
            printf("Wynik: %f", s);
            break;
        case '-' :
            s = roznica(a,b);
            printf("Wynik: %f", s);
            break;
        case '*' :
            s = iloczyn(a,b);
            printf("Wynik: %f", s);
            break;
        case '/' :
            s = iloraz(a,b);
            printf("Wynik: %f", s);
            break;
        default:
            printf("Nie rozpoznano operatora!");
    }
}

float suma(float a, float b){
    return a +b ;
}
float roznica(float a, float b){
    return a-b;

}
float iloczyn(float a, float b){
    return a*b;
}
float iloraz(float a, float b){
    if (b==0){
        printf("Blad: Dzielenie przez 0\n");
        return 0;
    } else {
        return a/b;
    }
}