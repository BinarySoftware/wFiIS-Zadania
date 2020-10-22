#include <stdio.h>
#include <stdlib.h>

double sum (double t[], int len){
    int i;
    double ss = 0.;
    for (i=0; i<len; ss+=t[i++]);
    return ss;
}

//---------------------------

double avg (double t[], int len){
    double ss = sum(t,len)/len;
    return ss;
}

//---------------------------

double min (double t[], int len){
    int i;
    int min = 0;
    for (i=0; i<len; i++)
        if (t[i]<t[min]) min=i;
    return t[min];
}

//---------------------------

double max (double t[], int len){
    int i;
    int max = 0;
    for (i=0; i<len; i++)
        if (t[i]>t[max]) max=i;
    return t[max];
}



struct fun {
    char * name;
    double (*f)(double*, int);
};

struct fun * fun_tab(double (*TAB_FUN[])(double*, int), char *names[], int var){
    struct fun * wskFunTab = malloc(var * sizeof(struct fun));
    for (int i = 0; i < var; i++){
        struct fun tempFun = {names[i], TAB_FUN[i]};
        wskFunTab[i] = tempFun;
    }
    return wskFunTab;
}

/// @param tab     - tablica struktur
/// @param len_tab - długość tablicy tab
/// @param t       - tablica liczb typu double
/// @param len_t   - długość tablicy t
void fun_prn(struct fun* tab, int len_tab, double* t, int len_t){
    for (int i = 0; i < len_t; i++){
        printf("%s --> %.1f\n", tab[i].name, tab[i].f(t, len_t));
    }
}

/// @param T_F     - tablica struktur
/// @param number  - element z T_F
/// @param d       - tablica tablic liczb typu double
/// @param len     - długość tablicy d
double * fun_find(struct fun *T_F, int number, double(*d)[4], int len ){
    double * min = d[0];
    for (int i = 1; i<len; i++){
        double minWynik = T_F[number].f(min,4);
        double bWynik = T_F[number].f(d[i],4);
        if(bWynik<minWynik){
            min = d[i];
        }
    }
    return min;
}

int main() {
    double (*TAB_FUN[])(double*, int) = {sum, avg, min, max};
    char *names[] = {"sum", "avg", "min", "max"};
    double data[][4] = {{1.3, 1.2, 0.2, 2.3}, {3.4, 1.1, 1.1, 2.1}, {0.4, 0.9, 2.3, 1.3},{2.3, 0.6, 1.1}};

    struct fun *wsk_fun = fun_tab(TAB_FUN,names, 4);
    for (int i = 0; i<4; i++){
        printf("Wiersz %d\n", i);
        fun_prn(wsk_fun, 4, data[i], 4);
    }

    double * minAvg = fun_find(wsk_fun, 1, data,4);
    printf("\nWiersz o minimalnej avg:\n");
    for (int i = 0; i < 4; i++){
        printf("%.1f, ", minAvg[i]);
    }
    printf("\n");

    return 0;
}
