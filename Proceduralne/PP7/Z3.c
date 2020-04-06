#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** podziel(char *, int * );

void sort(char **, int);

char* sklej(char **, int);

int main(int argc, char **argv) {
    char * wyraz = argv[1];
    int iloscStringow = 0;

    char ** arr = podziel(wyraz, &iloscStringow);
    sort(arr, iloscStringow);
    char * out = sklej(arr, iloscStringow);
    puts(out);

    return 0;
}


void sort(char ** arrOfStrings, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (strcmp(arrOfStrings[j], arrOfStrings[j + 1]) > 0) {
                char * temp = arrOfStrings[j + 1];
                arrOfStrings[j + 1]=arrOfStrings[j];
                arrOfStrings[j]=temp;
            }
        }
    }
}

char** podziel(char * input, int * n){
    char korektor[] = " ,;.:-"; // ',' ' ' ';' '.' ':'
    char * temp;
    char ** arr = malloc(*n * sizeof(char*));

    temp = strtok(input, korektor );
    while(temp != NULL ){
        int zawiera = 0;
        for(int i = 0; i<*n; i++){
            if(strcmp(temp,arr[i]) == 0){
                zawiera++;
            }
        }

        if (zawiera == 0) {
            *n += 1;
            arr = realloc(arr, *n*sizeof(char*));
            arr[*n-1] = temp;
        }

        temp = strtok(NULL, korektor );
    }
    return arr;
}

char* sklej(char ** arrOfStrings, int n){
    char * result = malloc(sizeof(char));
    for(int i = 0; i < n; i++) {
        result = realloc(result, (strlen(result) + 1 + strlen(arrOfStrings[i]))* sizeof(char));
        result = strcat(result, arrOfStrings[i]);
        result = strcat(result, " ");
    }
    return result;
}