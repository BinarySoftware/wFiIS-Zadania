#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct xyz {
    char znak;
    struct xyz * pt;
};

struct xyz * read_xyz_arr_from_bin(FILE * plik){
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

void xyz_decl_print_change(struct xyz *a, struct xyz *b, struct xyz *c) {
    // Przypisanie znakow przez zmienna 'a'
    a->znak = 'a';
    a->pt->znak = 'b';
    a->pt->pt->znak = 'c';

    // Odczyt znakow przez zmienna 'b'
    printf("%c ,", b->pt->pt->znak);
    printf("%c ,", b->znak);
    printf("%c \n", b->pt->znak);

    // Zmiana i odczyt znakow przez zmienna 'c'
    c->znak = c->znak - 32;
    c->pt->znak = c->pt->znak - 32;
    c->pt->pt->znak = c->pt->pt->znak - 32;

    printf("%c ,", c->pt->znak);
    printf("%c ,", c->pt->pt->znak);
    printf("%c \n", c->znak);
}

void save_xyz_to_txt(struct xyz *a, struct xyz *b, struct xyz *c){
    FILE* data_text = fopen("data.txt", "w");
    if(data_text==NULL) {
        printf("Nie mozna otworzyc pliku\n");
        return;
    }

    fprintf(data_text, "%c %p\n", a->znak, a->pt);
    fprintf(data_text, "%c %p\n", b->znak, b->pt);
    fprintf(data_text, "%c %p\n", c->znak, c->pt);

    fclose(data_text);
}

void save_xyz_to_bin(struct xyz *a, struct xyz *b, struct xyz *c){
    FILE* data_bin = fopen("data.dat", "wb");
    if(data_bin==NULL) {
        printf("Nie mozna otworzyc pliku\n");
        return;
    }

    fwrite(a, 1, sizeof(struct xyz), data_bin);
    fwrite(b, 1, sizeof(struct xyz), data_bin);
    fwrite(c, 1, sizeof(struct xyz), data_bin);

    fclose(data_bin);
}

void read_bin(){
    FILE* data_bin = fopen("data.dat", "rb");
    if(data_bin==NULL) {
        printf("Nie mozna otworzyc pliku\n");
        return;
    }

    struct xyz * t = read_xyz_arr_from_bin(data_bin);
    int i = 0;

    printf("\nOdczyt z pliku binarnego:\n");
    while (t[i].znak != 0 || t[i].pt != NULL){
        printf("%c, %p\n",t[i].znak,t[i].pt);
        i++;
    }

    free(t);
}

int main() {
    struct xyz a, b, c;
    a.pt = &b;
    b.pt = &c;
    c.pt = &a;

    xyz_decl_print_change(&a, &b, &c);

    // Zapisanie zmiennych do plikow
    save_xyz_to_txt(&a,&b,&c);

    save_xyz_to_bin(&a,&b,&c);

    // Odczyt z pliku binarnego
    read_bin();

    return 0;
}

