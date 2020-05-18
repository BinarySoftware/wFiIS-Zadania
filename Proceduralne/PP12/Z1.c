#include <stdlib.h>
#include <stdio.h>

struct Klient{
    char f_name[10];
    char l_name[10];
    char code[8];
    int age;
};

struct Klient * struct_klient_tab_from_file(int * rozm, char * name){
    FILE *file;
    file=fopen(name, "r");
    struct Klient * tab = malloc(sizeof(struct Klient));
    *rozm = 0;
    if(file != NULL) {
        while (!feof(file)) {
            tab = realloc(tab, (*rozm + 1) * sizeof(struct Klient));
            fscanf(file, "%s", tab[*rozm].l_name);
            fscanf(file, "%s", tab[*rozm].f_name);
            fscanf(file, "%s", tab[*rozm].code);
            fscanf(file, "%d", &tab[*rozm].age);
            (*rozm)++;
        }
        fclose(file);
    }
    return tab;
}

int main(int argc, char** argv) {
    int rozm = 0;
    struct Klient * tabTxt = struct_klient_tab_from_file(&rozm, "spis.txt");

    printf("Tablica klientow z pliku tekstowego:\n");
    for (int i=0;i<6;i++){
        printf("imie: %s\tnazwisko: %s\tkod pocztowy: %s\twiek: %d\n", tabTxt[i].f_name, tabTxt[i].l_name, tabTxt[i].code, tabTxt[i].age);
    }

    FILE *fb;
    fb=fopen("tabTxt.dat","wb+");
    fwrite(tabTxt, sizeof(struct Klient), rozm, fb);
    fclose(fb);

    fb=fopen("tabTxt.dat","rb");
    printf("\nKlienci pelnoletni z pliku binarnego:\n");
    for(int i=0; i<rozm; i++) {
        struct Klient person;
        fread(&person, sizeof(struct Klient), 1, fb);
        if(person.age >= 18){
            printf("imie: %s\tnazwisko: %s\tkod pocztowy: %s\twiek: %d\n", person.f_name, person.l_name, person.code, person.age);
        }
    }
    fclose(fb);

    return 0;
}