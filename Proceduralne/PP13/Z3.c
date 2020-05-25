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
/// Funkcja usuwajaca wszystkie elementy z listy jednokierunkowej
///
struct tnode * usun_elementy(struct tnode** head, char val){
    struct tnode *left_elem_head = NULL;

    if(*head){
        char lower, upper;

        if (val >= 'A' && val <= 'Z'){
            upper = val;
            lower = val + 32;
        } else {
            lower = val;
            upper = val - 32;
        }

        struct tnode* temp = NULL;
        while(*head && (((*head)->value == upper) || ((*head)->value == lower))){
            left_elem_head = dodaj_na_koniec(left_elem_head, (*head)->value);
            temp = *head;
            *head = (*head)->next;
            free(temp);
        }

        struct tnode* c_node = *head;
        while(c_node->next){
            if((c_node->next->value == upper) || (c_node->next->value == lower)){
                left_elem_head = dodaj_na_koniec(left_elem_head, c_node->next->value);
                temp = c_node->next;
                c_node->next = c_node->next->next;
                free(temp);
            } else {
                c_node = c_node->next;
            }
        }
    }

    return left_elem_head;
}

///
/// MAIN
///
int main(int argc, char** argv) {
    struct tnode *lista_head = NULL;
    lista_head = dodaj_na_koniec(lista_head, 'a');
    lista_head = dodaj_na_koniec(lista_head, 't');
    lista_head = dodaj_na_koniec(lista_head, 'o');
    lista_head = dodaj_na_koniec(lista_head, 'k');
    lista_head = dodaj_na_koniec(lista_head, ' ');
    lista_head = dodaj_na_koniec(lista_head, 'a');
    lista_head = dodaj_na_koniec(lista_head, 'm');
    lista_head = dodaj_na_koniec(lista_head, ' ');
    lista_head = dodaj_na_koniec(lista_head, 'a');
    lista_head = dodaj_na_koniec(lista_head, 'l');
    lista_head = dodaj_na_koniec(lista_head, 'A');
    printf("PRZED: head ");
    wypisz(lista_head);

    printf("wywolanie funkcji dla liter 'a'\n");
    struct  tnode *lista_usunietych = usun_elementy(&lista_head, 'a');
    printf("PO: head ");
    wypisz(lista_head);
    printf("    left ");
    wypisz(lista_usunietych);

    zwolnij(lista_head);
    zwolnij(lista_usunietych);
    return 0;
}