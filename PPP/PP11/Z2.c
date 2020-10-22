#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void file_copy (FILE * source, FILE * dest){
    fseek(source, 0L, SEEK_END);
    long int size = ftell(source);
    fseek(source, 0L, SEEK_SET);
    char* buffer = malloc(size*sizeof(char));
    fread(buffer, 1, size, source);
    fwrite(buffer, 1, size, dest);
}

int file_cmp (char * name1, char * name2){
    FILE * plik1 = fopen(name1, "rb");
    fseek(plik1, 0, SEEK_END);
    long int size1 = ftell(plik1);
    fseek(plik1, 0, SEEK_SET);
    void * mem1 = malloc(size1);
    fread(mem1, 1, size1, plik1);
    fclose(plik1);

    FILE * plik2 = fopen(name2, "rb");
    fseek(plik2, 0, SEEK_END);
    long int size2 = ftell(plik2);
    fseek(plik2, 0, SEEK_SET);
    void * mem2 = malloc(size2);
    fread(mem2, 1, size2, plik2);
    fclose(plik2);

    if(size1 != size2) {
        return 1;
    }
    return memcmp(mem1, mem2, size1) != 0;
}


int main(void){
    // Sprawdzanie i kopiowanie zawartosci pliku txt
    int diff = file_cmp("file_t.txt","file_t_1.txt");
    if (diff == 0) {
        printf("Pliki tekstowe takie same przed kopiowaniem\n");
    } else {
        printf("Pliki tekstowe rozne przed kopiowaniem\n");
    }

    FILE * src = fopen("file_t.txt", "r");
    FILE * dest = fopen("file_t_1.txt", "w");
    file_copy(src, dest);
    fclose(src);
    fclose(dest);

    diff = file_cmp("file_t.txt","file_t_1.txt");
    if (diff == 0) {
        printf("Pliki tekstowe takie same po kopiowaniu\n");
    } else {
        printf("Pliki tekstowe rozne po kopiowaniu\n");
    }


    // Sprawdzanie i kopiowanie zawartosci pliku bin
    int diff2 = file_cmp("file_b","file_b_1");
    if (diff2 == 0) {
        printf("Pliki binarne takie same przed kopiowaniem\n");
    } else {
        printf("Pliki binarne rozne przed kopiowaniem\n");
    }

    src = fopen("file_b", "rb");
    dest = fopen("file_b_1", "wb");
    file_copy(src, dest);
    fclose(src);
    fclose(dest);

    diff2 = file_cmp("file_b","file_b_1");
    if (diff2 == 0) {
        printf("Pliki binarne takie same po kopiowaniu\n");
    } else {
        printf("Pliki binarne rozne po kopiowaniu\n");
    }

    return 0;
}
