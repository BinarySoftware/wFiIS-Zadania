//
// Created by Maciej Mikołajek on 08/01/2020.
//
#include <stdio.h>
#include <ctype.h>

void funkcja(char * lancuch);

int main(void){
    char str[] = "To jest TESTOWY\tlancuch\nfoo";
    printf("PRZED: %s\n",str);
    funkcja(str);
    printf("PO   : %s\n",str);
    return 0;
}

void funkcja(char * lancuch){
    unsigned char i = 0;

    while (1){
        if ( isspace(lancuch[i])){
            /* Usuwa wszystkie białe znaki poprzez przesunięcie elementów */
            unsigned char j = i;
            while (1){
                lancuch[j] = lancuch[j+1];
                if (lancuch[j+1] == '\0'){
                    break;
                }
                j++;
            }
        }
        if (lancuch[i] == '\0'){
            break;
        }
        i++;
    }
}