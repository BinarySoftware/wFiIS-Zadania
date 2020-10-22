#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void print_string_array(char ** strings, size_t strings_len);//procedura wypisująca tablicę stringów
char * min_string (char ** strings, size_t strings_len); //znajdowanie najmniejszego stringu w sensie leksykalnym w tablicy stringów - zwraca wskaźnik do minimalnego

int main(){
    char * strings[] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"};
    char * wsk_string;
    size_t strings_len = sizeof(strings)/sizeof(strings[0]); //okreslenie długości tablicy strings
    print_string_array(strings, strings_len); //wypisanie tablicy stringów
    wsk_string = min_string(strings,strings_len);//znalezienie najmniejszego stringu w tablicy
    printf("Najmniejszy string: %s\n", wsk_string); //wypisanie najmniejszego stringu
    return 0;
}

void print_string_array(char ** strings, size_t strings_len){
    printf("TABLICA STRINGÓW:\n");
    for(int i = 0; i<strings_len; i++){
        puts(strings[i]);
    }
    printf("\n");
}

char * min_string (char ** strings, size_t strings_len){
    char * min = strings[0];
    for(int i = 1; i<strings_len; i++){
        int cmp = strcmp(min, strings[i]);
        if (cmp>0){
            min = strings[i];
        }
    }
//    for(int i = 1; i<strings_len; i++){
//        unsigned long len_min = strlen(min);
//        unsigned long len_s = strlen(strings[i]);
//        if (len_s<len_min){
//            min = strings[i];
//        }
//    }
    return min;
}