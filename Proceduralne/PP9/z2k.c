#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int cstring_cmp(const void * a, const void * b){
    const char *key = a;
    const char *const *arg = b;
    return strcmp(key, *arg);
}
int numcompare(const void * a, const void * b){
    double f = fabs(*(double*)a - *(double*)b);
    if (f < 1e-3){
        return 0;
    }

    if (*(double*)a > *(double*)b) return 1;
    else if (*(double*)a < *(double*)b) return -1;
    else return 0;
}

int main(int argc, char *argv[]){
    int count=0,i;
    char *szukaj="Alex";
    double l=5.55;
    //printf("%d\n",sizeof(char**));
    //char *strings[] = {"Alex","Bill","Celine","Dexter","Forest","Garcia"};
    char *strings[]={"Alex","Alex","Celine","Bill","Dexter"};
    double numbers[] = {1.34, 4.34, 5.55, 5.55, 5.55, 8.1, 9.12, 11.23};
    double *ptr = NULL;
    char **pt = NULL;

    for (i=0;i<sizeof(strings)/sizeof(strings[0]);i++){
        char ** ptNext=bsearch(szukaj,strings,sizeof(strings)/sizeof(strings[0]),sizeof(strings[0]),cstring_cmp);
        if(ptNext!=NULL){
            count++;		//wynik
            pt = ptNext;
            strings[pt-strings]="a";

        } else break;
    }
    for(i=0;i<sizeof(strings)/sizeof(strings[0]);i++){
        if (strcmp(strings[i],"a") == 0){
            strings[i] = szukaj;
        }
        //printf("%s ",strings[i]);
    }
    if(pt == 0){
        printf("%s nie wystepuje w tab", szukaj);
    }else{
        printf("%s\tna pozycji %ld\tilosc %d\n",*pt,pt-strings+1,count);
    }

    count=0;
    for (i=0;i<sizeof(numbers)/sizeof(numbers[0]);i++){
        double * ptrNext=bsearch(&l,numbers,sizeof(numbers)/sizeof(numbers[0]),sizeof(numbers[0]),numcompare);
        if(ptrNext!=NULL){
            count++;
            ptr = ptrNext;
            //printf("%.2f\tna pozycji %ld\tilosc %d\n",*ptr,ptr-numbers+1,count);
            numbers[ptr-numbers]=0.0;
        }else break;
    }
    for(i=0;i<sizeof(numbers)/sizeof(numbers[0]);i++){
        //printf("%.2f - ",numbers[i]);
        if (fabs(numbers[i]) < 1e-6){
            numbers[i] = l;
        }
        //printf("%.2f\n",numbers[i]);
    }
    if(ptr == 0){
        printf("%.2f nie wystepuje w tab", l);
    }else{
        printf("%.2f\tna pozycji %ld\tilosc %d\n",*ptr,ptr-numbers+1,count);
    }
    return 0;
}