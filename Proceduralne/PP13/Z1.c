#include <stdlib.h>
#include <stdio.h>

///
/// Struktura tworzaca jeden element listy jednokierunkowej
///
struct tnode{
    char value;
    struct tnode *next;
};

///
/// Funkcja zwalniajaca pamiec zajmowana przez liste jednokierunkowa
///
void zwolnij(struct tnode *list){
    struct tnode *next_ptr = NULL;
    while (list != NULL){
        next_ptr = list->next;
        free(list);
        list = next_ptr;
    }
}

///
/// Funkcja wypisujaca liste jednokierunkowa
///
void wypisz(struct tnode *head){
    while (head != NULL){
        printf("-> ['%c'] ",head->value);
        head = head->next;
    }
    printf("-> NULL\n");
}

///
/// Funkcja odwracajaca liste jednokierunkowa
///
struct tnode * odwroc_liste(struct tnode *head){
    struct tnode *odwr_head;
    if (head == NULL || head->next == NULL){
        return head;
    }

    odwr_head = odwroc_liste(head->next);
    head->next->next = head;
    head->next = NULL;

    return odwr_head;
}

///
/// Funkcja dodajaca element na poczatek listy jednokierunkowej
///
struct tnode * dodaj_na_poczatek(struct tnode *head, char val){
    struct tnode *new_head = malloc(sizeof(struct tnode));
    new_head->next = head;
    new_head->value = val;
    return new_head;
}

///
/// Funkcja dodajaca element na koniec listy jednokierunkowej
///
struct tnode * dodaj_na_koniec(struct tnode *head, char val){
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

///
/// MAIN
///
int main(int argc, char** argv) {
    struct tnode *lista_head = NULL;
    lista_head = dodaj_na_koniec(lista_head, 'f');
    lista_head = dodaj_na_koniec(lista_head, 'd');
    lista_head = dodaj_na_koniec(lista_head, 'u');
    lista_head = dodaj_na_koniec(lista_head, 'i');
    printf("PRZED: head ");
    wypisz(lista_head);
    lista_head = odwroc_liste(lista_head);
    printf("PO   : head ");
    wypisz(lista_head);
    zwolnij(lista_head);
    return 0;
}