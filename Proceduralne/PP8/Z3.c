#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// KOMPARATORY
int double_cmp(const void * a, const void * b){ //komparator dla double
    if (*(double*)a > *(double*)b) return 1;
    else if (*(double*)a < *(double*)b) return -1;
    else return 0;
}

int cstring_cmp(const void * a, const void * b){ //komparator dla stringow
    const char **stra = (const char **)a;
    const char **strb = (const char **)b;
    return strcmp(*stra, *strb);
}

int tabchars_cmp(const void * a, const void * b) { //komparator dla tablicy napisow
    return strcmp(a, b);
}

/// PRINTING
void print_double_array(double * arr,int n) { //wypisywanie tablicy double
    printf("Double Array:\n");
    for (int i = 0; i<n; i++){
        printf("%d.\t%f\n", i, arr[i]);
    }
    printf("\n");
}

void print_cstring_array(char ** arr,int n) { //wypisywanie tablicy string'ow
    printf("String Array:\n");
    for (int i = 0; i<n; i++){
        printf("%d.\t%s\n", i, arr[i]);
    }
    printf("\n");
}

void print_tabchars_array(char arr[][10] ,int n) {  //wypisywanie tablicy napisow
    printf("Char Tab Array:\n");
    for (int i = 0; i<n; i++){
        printf("%d.\t%s\n", i, arr[i]);
    }
    printf("\n");
}

/// SORTING
void sort_double_example() { //sortowanie tablicy double
    double numbers[] = { 7.4, 1.3, 14.5, 0.1, -1.0, 2.3, 1,2, 43.0, 2.0, -4.7, 5.8 };
    size_t number_size = sizeof(numbers[0]);
    size_t numbers_len = sizeof(numbers)/number_size; //okreslenie dlugosci tablicy

    puts("*** Double sorting...");
    print_double_array(numbers, numbers_len); //wypisanie tablicy double przed sortowaniem
    qsort(numbers, numbers_len, number_size, double_cmp); //sortowanie tablicy double
    print_double_array(numbers, numbers_len); //wypisanie tablicy double po sortowaniu
}

void sort_cstrings_example() { //sortowanie tablicy stringow
    char *strings[] = {"Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"};
    size_t string_size = sizeof(strings[0]);
    size_t strings_len = sizeof(strings)/string_size; //okreslenie dlugosci tablicy

    puts("*** String sorting...");
    print_cstring_array(strings, strings_len); //wypisanie tablicy stringow przed sortowaniem
    qsort(strings, strings_len, string_size, cstring_cmp);//sortowanie tablicy stringow
    print_cstring_array(strings, strings_len);
}

void sort_tabchars_example() { //sortowanie tablicy stringow
    char tab_char[][10] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"};
    size_t tab_char_one_size = sizeof(tab_char[0]);
    size_t tab_char_N = sizeof(tab_char)/tab_char_one_size; //okreslenie ilosci napisow w tablicy

    puts("*** table sorting...");
    print_tabchars_array(tab_char, tab_char_N); //wypisanie tablicy napisow przed sortowaniem
    qsort(tab_char, tab_char_N, tab_char_one_size, tabchars_cmp); //sortowanie tablicy stringow funkcja qsort
    print_tabchars_array(tab_char, tab_char_N); //wypisanie tablicy napisow sortowaniu
}

// MAIN program (wywołanie funkcji sortujacych)
int main() {
    sort_double_example();
    sort_cstrings_example();
    sort_tabchars_example();
    return 0;
}