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
/// Funkcja konkatenujaca dwie listy jednokierunkowe
///
struct tnode * konkatenacja_posortowana(struct tnode ** lista_1, struct tnode ** lista_2){
    struct tnode *lista_head = NULL;
    struct tnode *current = NULL;
    // Obydwie listy niepuste
    while (*lista_1 != NULL && *lista_2 != NULL){
        if((*lista_1)->value < (*lista_2)->value){
            if (lista_head == NULL) {
                lista_head = *lista_1;
                *lista_1 = (*lista_1)->next;
                lista_head->next = NULL;
                current = lista_head;
            } else {
                current->next = *lista_1;
                *lista_1 = (*lista_1)->next;
                current = current->next;
                current->next = NULL;
            }
        } else {
            if (lista_head == NULL) {
                lista_head = *lista_2;
                *lista_2 = (*lista_2)->next;
                lista_head->next = NULL;
                current = lista_head;
            } else {
                current->next = *lista_2;
                *lista_2 = (*lista_2)->next;
                current = current->next;
                current->next = NULL;
            }
        }
    }
    // Przepisywanie co zostalo
    while (*lista_1 != NULL){
        current->next = *lista_1;
        *lista_1 = (*lista_1)->next;
        current = current->next;
        current->next = NULL;
    }
    while (*lista_2 != NULL){
        current->next = *lista_2;
        *lista_2 = (*lista_2)->next;
        current = current->next;
        current->next = NULL;
    }
    return lista_head;
}

///
/// MAIN
///
int main(int argc, char** argv) {
    struct tnode *lista_1 = NULL;
    lista_1 = dodaj_na_koniec(lista_1, 'a');
    lista_1 = dodaj_na_koniec(lista_1, 'k');
    lista_1 = dodaj_na_koniec(lista_1, 'l');
    lista_1 = dodaj_na_koniec(lista_1, 'z');

    struct tnode *lista_2 = NULL;
    lista_2 = dodaj_na_koniec(lista_2, 'a');
    lista_2 = dodaj_na_koniec(lista_2, 'b');
    lista_2 = dodaj_na_koniec(lista_2, 'n');
    lista_2 = dodaj_na_koniec(lista_2, 'l');
    lista_2 = dodaj_na_koniec(lista_2, 'w');

    printf("PRZED: lista 1 ");
    wypisz(lista_1);
    printf("       lista 2 ");
    wypisz(lista_2);

    printf("PO: lista ");
    struct tnode *lista = konkatenacja_posortowana(&lista_1, &lista_2);
    wypisz(lista);
    printf("    lista 1 ");
    wypisz(lista_1);
    printf("    lista 2 ");
    wypisz(lista_2);

    zwolnij(lista);
    zwolnij(lista_1);
    zwolnij(lista_2);
    return 0;
}