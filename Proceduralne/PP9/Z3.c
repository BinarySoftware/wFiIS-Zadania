//
// Created by Maciej Mikołajek on 28/04/2020.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// KLIENT
typedef struct {
    char f_name[BUFSIZ];
    char l_name[BUFSIZ];
    char code[BUFSIZ];
    int age;
} Klient;

/// KOMPARATOR
int klient_cmp(const void * a, const void * b){
    Klient *KlientA = (Klient *)a;
    Klient *KlientB = (Klient *)b;

    int dif = strcmp(KlientA->l_name, KlientB->l_name);
    if (dif != 0){
        return dif;
    } else {
        int dif2 = strcmp(KlientA->f_name, KlientB->f_name);
        return dif2;
    }
}

/// PRINTER
void printKlient(Klient k){
    printf("%s\t%s\tkod: %s\twiek: %d\n", k.l_name, k.f_name, k.code, k.age);
}

/// MAIN
int main() {
    Klient tab[6];

    for(int i = 0; i < 6; i++){
        char fName[BUFSIZ], lName[BUFSIZ], code[BUFSIZ], age[BUFSIZ];
        fgets(lName,BUFSIZ,stdin);
        fgets(fName,BUFSIZ,stdin);
        fgets(code,BUFSIZ,stdin);
        fgets(age,BUFSIZ,stdin);

        // Usuwanie '\n'
        lName[strlen(lName)-2] = '\0';
        fName[strlen(fName)-2] = '\0';
        code[strlen(code)-2] = '\0';

        strcpy(tab[i].f_name, fName);
        strcpy(tab[i].l_name, lName);
        strcpy(tab[i].code, code);
        tab[i].age = atoi(age);
    }

    printf("Klienci:\n");
    for (int k = 0; k < 6; ++k) {
        printKlient(tab[k]);
    }
    size_t klientSize = sizeof(Klient);
    qsort(tab, 6, klientSize, klient_cmp);
    printf("\nPo posortowaniu:\n");
    for (int k = 0; k < 6; ++k) {
        printKlient(tab[k]);
    }
    return 0;
}
