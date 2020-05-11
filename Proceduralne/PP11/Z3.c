#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct xyz {
    char znak;
    struct xyz * pt;
};

struct xyz * xyzFileReader(FILE * plik){
    int ilElem = 0;
    struct xyz *tab = NULL;
    while(!feof(plik)) {
        ilElem++;
        tab = realloc(tab, ilElem * sizeof(struct xyz));
        fread(tab+(ilElem-1), 1, sizeof(struct xyz), plik);
    }
    fclose(plik);
    return tab;
}

int main() {
    struct xyz a, b, c;
    a.pt = &b;
    b.pt = &c;
    c.pt = &a;

    // Przypisanie znakow przez zmienna 'a'
    a.znak = 'a';
    a.pt->znak = 'b';
    a.pt->pt->znak = 'c';

    // Odczyt znakow przez zmienna 'b'
    printf("%c ,", b.pt->pt->znak);
    printf("%c ,", b.znak);
    printf("%c \n", b.pt->znak);

    // Zmiana i odczyt znakow przez zmienna 'c'
    c.znak = c.znak-32;
    c.pt->znak = c.pt->znak-32;
    c.pt->pt->znak = c.pt->pt->znak-32;

    printf("%c ,", c.pt->znak);
    printf("%c ,", c.pt->pt->znak);
    printf("%c \n", c.znak);

    // Zapisanie zmiennych do plikow
    FILE* data_text = fopen("data.txt", "w");
    if(data_text==NULL) {
        printf("Nie mozna otworzyc pliku\n");
        return -1;
    }

    fprintf(data_text, "%c %p\n", a.znak, a.pt);
    fprintf(data_text, "%c %p\n", b.znak, b.pt);
    fprintf(data_text, "%c %p\n", c.znak, c.pt);

    fclose(data_text);


    FILE* data_bin = fopen("data.dat", "wb");
    if(data_bin==NULL) {
        printf("Nie mozna otworzyc pliku\n");
        return -1;
    }

    fwrite(&a, 1, sizeof(struct xyz), data_bin);
    fwrite(&b, 1, sizeof(struct xyz), data_bin);
    fwrite(&c, 1, sizeof(struct xyz), data_bin);

    fclose(data_bin);

    // Odczyt z pliku binarnego
    data_bin = fopen("data.dat", "rb");
    if(data_bin==NULL) {
        printf("Nie mozna otworzyc pliku\n");
        return -1;
    }

    struct xyz * t = xyzFileReader(data_bin);
    int i = 0;

    printf("\nOdczyt z pliku binarnego:\n");
    while (t[i].znak != 0 || t[i].pt != NULL){
        printf("%c, %p\n",t[i].znak,t[i].pt);
        i++;
    }

    free(t);

    return 0;
}

