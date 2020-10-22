#include <stdlib.h>
#include <stdio.h>

struct tnode{
    char value;
    struct tnode *next;
};

struct tnode * dodaj_na_poczatek(struct tnode *head, char val){
    struct tnode *new_head = malloc(sizeof(struct tnode));
    new_head->next = head;
    new_head->value = val;
    return new_head;
}

void zwolnij(struct tnode *list){
    struct tnode *next_ptr = NULL;
    while (list != NULL){
        next_ptr = list->next;
        free(list);
        list = next_ptr;
    }
}

void wypisz(struct tnode *head){
    while (head != NULL){
        printf("%c, ",head->value);
        head = head->next;
    }
}

int main(int argc, char** argv) {
    struct tnode *lista_head = NULL;
    lista_head = dodaj_na_poczatek(lista_head, 'a');
    lista_head = dodaj_na_poczatek(lista_head, 'c');
    lista_head = dodaj_na_poczatek(lista_head, 'v');
    lista_head = dodaj_na_poczatek(lista_head, 'f');
    lista_head = dodaj_na_poczatek(lista_head, 't');
    wypisz(lista_head);
    zwolnij(lista_head);
    return 0;
}
