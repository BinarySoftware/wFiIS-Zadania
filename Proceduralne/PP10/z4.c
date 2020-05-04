#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ROW 6
#define COL 4

int rand_int(int a, int b) {
    return (a + rand()%(b-a+1));
}

int sum (int t[], int len){
    int i;
    int ss = 0;
    for (i=0; i<len; ss+=t[i++]);
    return ss;
}

//---------------------------

double avg (int t[], int len){
    double ss = (double)sum(t,len)/len;
    return ss;
}

void printTab(int a, int b, int tab[][b]){
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            printf("%3d\t", tab[i][j]);
        }
        printf("%f", avg(tab[i], COL));
        printf("\n");
    }
}

int qsort_cmp(const void * a, const void * b){
    int *liA = (int *)a;
    int *liB = (int *)b;

    double avgA = avg(liA, COL);
    double avgB = avg(liB, COL);

    if (avgA > avgB) return 1;
    else if (avgA < avgB) return -1;
    else return 0;
}

int bsearch_cmp(const void * a, const void * b){
    double sz = *(double *)a;
    int *liB = (int *)b;

    double avgB = avg(liB, COL);

    double diffPercent = (avgB - sz)/avgB;

    if (fabs(diffPercent) <= 0.01) return 0;

    if (sz > avgB) return 1;
    else if (sz < avgB) return -1;
    else return 0;
}

int main() {
    srand(time(0));
    int TAB[ROW][COL];

    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            TAB[i][j] = rand_int(-10, 10);
        }
    }

    printf("TABLICA NA POCZATKU:\n");
    printTab(ROW, COL, TAB);

    qsort(TAB, ROW, sizeof(TAB[0]), qsort_cmp);

    printf("TABLICA POSORTOWANA ROSNACO AVG:\n");
    printTab(ROW, COL, TAB);

    double szukanaAvg;
    printf("Podaj poszukiwaną średnią: ");
    scanf("%lf", &szukanaAvg);

    int * pt = bsearch(&szukanaAvg,TAB,ROW,sizeof(TAB[0]),bsearch_cmp);

    if(pt == 0){
        printf("Nie znaleziono wiersza o podanej sredniej.\n");
    } else {
        printf("Znaleziono wiersz o podanej sredniej, nr: %ld.\n", (pt-TAB[0])/COL);
        for (int j = 0; j < COL; j++) {
            printf("%d ", *(pt + j));
        }
        printf("\n");
    }
    return 0;
}
