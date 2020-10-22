#include <stdio.h>
#include <time.h>
#include <math.h>



double fun0(double x) { return log(x); }
double fun1(double x) { return x*x;    }
double fun2(double x) { return sin(x); }
double fun3(double x) { return cos(x); }

double (**findMax (double (*tabFun[])(double), double arg))(double);


int main(){
    double (*TAB_FUN[5])(double);

    TAB_FUN[0] = fun0;
    TAB_FUN[1] = fun1;
    TAB_FUN[2] = fun2;
    TAB_FUN[3] = fun3;
    TAB_FUN[4] = NULL;

    char * nazwy[]={"log", "pow","sin","cos"};
    char **str = nazwy;

    double (**wsk_fun)(double);
    wsk_fun = TAB_FUN;
    double data[8] = { 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0 };

    while(*wsk_fun) { //pętla po wskaźnikach do funkcji
        for (int i = 0; i < 8; i++) { //pętla po argumentach
            printf("%s(%.1f) = %.4f\n", *str, data[i], (*wsk_fun)(data[i]));
        }
        printf("\n");
        wsk_fun++;
        str++;
    }

    double (**wskMax)(double);
    double var = 0.05;
    wskMax = findMax(TAB_FUN, var);
    printf ("dla x= %f najwieksza wartosc ma %s, ktora wynosi %.3f\n",
            var, nazwy[wskMax - TAB_FUN], (*wskMax)(var));
    return 0;
}

double (**findMax (double (*tabFun[])(double), double arg))(double){
    int i=1, max=0;
    while (tabFun[i] != NULL){
        if (tabFun[i](arg) > tabFun[max](arg)) {
            max = i;
        }
        i++;
    }
    return tabFun + max;
}