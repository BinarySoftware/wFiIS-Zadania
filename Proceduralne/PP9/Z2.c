//
// Created by Maciej Mikołajek on 28/04/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/// KOMPARATORY
int cstring_cmp(const void * a, const void * b){
    const char *stra = a;
    const char * const *strb = b;
    return strcmp(stra, *strb);
}

int double_cmp(const void * a, const void * b){
    if (*(double*)a > *(double*)b) return 1;
    else if (*(double*)a < *(double*)b) return -1;
    else return 0;
}

/// MAIN
int main(){
    char szukanyString[]="Garcia";
    char *strings[] = { "Alex", "Bill","Bill","Celine", "Dexter", "Forest","Forest","Garcia","Garcia","Garcia", "Pedro","Zorro"};

    size_t string_size = sizeof(strings[0]);
    size_t strings_len = sizeof(strings)/string_size;

    char ** pt = bsearch(szukanyString, strings, strings_len, string_size, cstring_cmp);
    if (pt == 0){
        printf("Nie znaleziono '%s'\n", szukanyString);
    } else {
        int iloscWystapien = 0;
        for(int i = 0; i < strings_len; i++){
            if(strcmp(szukanyString, strings[i]) == 0){
                iloscWystapien++;
            }
        }
        printf("%s na pozycji %ld, wystepuje %d razy.\n",*pt, pt-strings, iloscWystapien);
    }



    double szukanyNumer = 5.67;
    double numbers[] = {1.34, 1.34, 4.34, 5.55, 5.67, 5.67, 5.67, 7.76, 8.1, 8.1, 9.12, 11.23};

    size_t number_size = sizeof(numbers[0]);
    size_t numbers_len = sizeof(numbers)/number_size;

    double * pt2 = bsearch(&szukanyNumer,numbers,numbers_len,number_size,double_cmp);
    if (pt2 == 0){
        printf("Nie znaleziono '%.2f'\n", szukanyNumer);
    } else {
        int iloscWystapien = 0;
        for(int i = 0; i < numbers_len; i++){
            if(fabs(szukanyNumer-numbers[i]) < 1e-6){
                iloscWystapien++;
            }
        }
        printf("%.2f na pozycji %ld, wystepuje %d razy.\n",*pt2, pt2-numbers, iloscWystapien);
    }
    return 0;
}
