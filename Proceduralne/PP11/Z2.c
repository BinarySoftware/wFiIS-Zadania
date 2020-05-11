#include <stdio.h>

void file_copy (FILE *source, FILE *dest){
    char ch;
    while(( ch = fgetc(source)) != EOF )
        fputc(ch, dest);
    fclose(source);
    fclose(dest);
}

int file_cmp (char *name1, char *name2){
    FILE* f1 = fopen(name1,"r");
    FILE* f2 = fopen(name2,"r");
    char ch1 = fgetc(f1);
    char ch2 = fgetc(f2);
    while (ch1 != EOF && ch2 != EOF) {
        if (ch1 != ch2) {
            return 1;
        }

        ch1 = fgetc(f1);
        ch2 = fgetc(f2);
    }

    if (ch1 == EOF && ch2 == EOF){
        return 0;
    } else {
        return 1;
    }
}


int main(void){
    FILE* src = fopen("file_t.txt", "r");
    FILE* dest = fopen("file_t_1.txt", "w");
    file_copy(src, dest);
    int diff = file_cmp("file_t.txt","file_t_1.txt");
    if (diff == 0) {
        printf("Pliki tekstowe takie same po kopiowaniu\n");
    } else {
        printf("Pliki tekstowe rozne po kopiowaniu\n");
    }

    src = fopen("file_b", "rb");
    dest = fopen("file_b_1", "wb");
    file_copy(src, dest);
    int diff2 = file_cmp("file_b","file_b_1");
    if (diff2 == 0) {
        printf("Pliki binarne takie same po kopiowaniu\n");
    } else {
        printf("Pliki binarne rozne po kopiowaniu\n");
    }

    return 0;
}
