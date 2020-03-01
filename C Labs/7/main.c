#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

void usunSpacje(char * str);

bool czyPosiadaOperator(char * str);

bool parse(char * str, double * l1, double * l2);

///=============================================================================
///=============================================================================
///=============================================================================
int main(int argc, char *argv[]) {
    if (argc > 1){
        char * str = argv[1];
        printf("%s = ", str);
        usunSpacje(str);

        bool posiadaOperator = czyPosiadaOperator(str);
        if (posiadaOperator){
            double l1 = 0;
            double l2 = 0;

            bool parsingSucceeded = parse(str, &l1, &l2);
            if (parsingSucceeded){
                if(l1 == 0 && l2 == 0){
                    printf("\nBlad matematyczny. Nie mozna wykonac 0^0.\n");
                } else {
                    double wynik = pow(l1, l2);
                    printf("%f", wynik);
                }
            } else {
                printf("\nNie podano liczby. Koniec programu.\n");
            }
        } else {
            printf ("\nNie znaleziono operatorow. Koniec programu.\n");
        }
    } else {
        printf("Nie podano argumentow. Koniec programu.\n");
    }
    return 0;
}

///=============================================================================
void usunSpacje(char * str){
    unsigned char i = 0;

    while (1){
        if ( isspace(str[i])){
            /* Usuwa wszystkie białe znaki poprzez przesunięcie elementów */
            unsigned char j = i;
            while (1){
                str[j] = str[j + 1];
                if (str[j + 1] == '\0'){
                    break;
                }
                j++;
            }
            i--;
        }
        if (str[i] == '\0'){
            break;
        }
        i++;
    }
}

///=============================================================================
bool czyPosiadaOperator(char * str){

    char * pchh;
    pchh = strstr (str,"^");
    if (pchh == NULL){
        pchh = strstr (str,"**");
        if (pchh == NULL){
            return false;
        } else {
            return true;
        }
    } else {
        return true;
    }
}

///=============================================================================
bool parse(char * str, double * l1, double * l2){
    int i = 1;
    char * pch;
    pch = strtok (str,"^*");
    while (pch != NULL)
    {
        if(strlen(pch)>0){
            if (i == 1){
                *l1 = atof(pch);
            } else if (i == 2){
                *l2 = atof(pch);
                return true;
            }
        } else {
            return false;
        }

        i++;
        pch = strtok (NULL, "^*");
    }
    return false;
}