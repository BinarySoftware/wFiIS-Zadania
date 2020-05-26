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
    struct tnode *node = list;
    struct tnode *next_ptr = NULL;
    while (node != NULL){
        next_ptr = node->next;
        free(node);
        node = next_ptr;
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
/// Funkcja dodajaca element do uporzadkowanej listy jednokierunkowej
///
void dodaj_uporzadkowane(struct tnode **head, char val){
    struct tnode *new_elem = malloc(sizeof(struct tnode));
    new_elem->value=val;
    new_elem->next=NULL;

    if (*head != NULL){
        if ((*head)->value > new_elem->value) {
            new_elem->next = *head;
            *head = new_elem;
            return;
        }

        struct tnode *temp = *head;
        while(temp->next != NULL){
            if (temp->next->value > new_elem->value) {
                new_elem->next = temp->next;
                temp->next = new_elem;
                return;
            }
            temp = temp->next;
        }
        temp->next = new_elem;
    } else {
        *head = new_elem;
    }
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
    lista_head = dodaj_na_koniec(lista_head, 'a');
    lista_head = dodaj_na_koniec(lista_head, 'j');
    lista_head = dodaj_na_koniec(lista_head, 'k');
    lista_head = dodaj_na_koniec(lista_head, 'z');
    printf("PRZED: head ");
    wypisz(lista_head);

    printf("Dodajemy: ['i']\n");
    dodaj_uporzadkowane(&lista_head, 'i');
    printf("PO   : head ");
    wypisz(lista_head);
    printf("Dodajemy: ['w']\n");
    dodaj_uporzadkowane(&lista_head, 'w');
    printf("PO   : head ");
    wypisz(lista_head);
    printf("Dodajemy: ['A']\n");
    dodaj_uporzadkowane(&lista_head, 'A');
    printf("PO   : head ");
    wypisz(lista_head);
    printf("Dodajemy: ['Z']\n");
    dodaj_uporzadkowane(&lista_head, 'Z');
    printf("PO   : head ");
    wypisz(lista_head);

    zwolnij(lista_head);
    return 0;
}