#include <stdlib.h>
#include <stdio.h>

struct tnode{
    char value;
    struct tnode *next;
};

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

struct tnode *dodajnakoniec(struct tnode *head, char val){
    struct tnode *new_last_elem = malloc(sizeof(struct tnode));
    new_last_elem->value=val;
    new_last_elem->next=NULL;

    if (head != NULL){
        struct tnode *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_last_elem;
    } else {
        head = new_last_elem;
    }
    return head;
}


int main(int argc, char** argv) {
    struct tnode *lista_head = NULL;
    lista_head = dodajnakoniec(lista_head, 'a');
    lista_head = dodajnakoniec(lista_head, 'c');
    lista_head = dodajnakoniec(lista_head, 'v');
    lista_head = dodajnakoniec(lista_head, 'f');
    lista_head = dodajnakoniec(lista_head, 't');
    wypisz(lista_head);
    zwolnij(lista_head);
    return 0;
}
