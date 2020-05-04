#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void va_cat(char ** result, int num, ...);

int main() {
    char * concatenated = malloc(sizeof(char));
    va_cat(&concatenated, 3, "If you never did You should.",
            "These things are fun.",
            "and Fun is good.");
    printf("%s\n\n", concatenated);


    va_cat(&concatenated, 4, "Sometimes ",
           "you will never know ",
           "the value of a moment ",
           "until it becomes a memory.");
    printf("%s\n", concatenated);
    return 0;
}

void va_cat(char ** result, int num, ...){
    strcpy(*result, ""); //oczyszczenie po poprzedniej konkatenacji
    va_list args;
    va_start(args, num);
    for(int i=0; i<num; i++){
        char * temp = va_arg(args, char *);
        *result = strcat(*result, temp);
    }
    va_end(args);
}