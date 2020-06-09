//
// Created by Maciej Mikołajek on 02/06/2020.
//

#include "cycle.h"

/// wypisywanie listy
void print_list(struct tnode* head){
    struct tnode* temp = head;
    if (head != NULL){
        while (temp != NULL && temp->next != head){
            printf(" -> [%d]", temp->value);
            temp = temp->next;
        }
        printf(" -> [%d]\n", temp->value);
    } else {
        printf("[PUSTA]\n");
    }
}

/// dodawanie elementu do listy
struct tnode* add_el(struct tnode* head, struct tnode* el){
    if (head != NULL && head->next != NULL){
        struct tnode *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = el;
        el->next = head;
    } else {
        head = el;
        el->next = head;
    }
    return head;
}

/// usuwanie elementu z listy, jeżeli mamy kilka elementów
/// o podanym kluczu usuwamy wszystkie
void del_el(struct tnode ** head, int var){
    int i = 0;
    int ilosc = 0;

    struct tnode *poprzedni, *biezacy;

    if (*head == NULL){
        return;
    }

    biezacy = *head;
    poprzedni = biezacy;

    // zliczanie ilosci elementow
    while (poprzedni->next != *head){
        poprzedni = poprzedni->next;
        ilosc++;
    }

    while (i <= ilosc){
        if (biezacy->value == var){
            if (biezacy->next != biezacy){
                poprzedni->next = biezacy->next;
            } else {
                poprzedni->next = NULL;
            }

            if (biezacy == *head) {
                *head = poprzedni->next;
            }

            free(biezacy);

            if (poprzedni != NULL){
                biezacy = poprzedni->next;
            } else {
                biezacy = NULL;
            }
        } else {
            poprzedni = biezacy;
            biezacy  = biezacy->next;
        }

        i++;
    }
}


/// łączenie dwóch list cyklicznych w jedną
struct tnode* add_list(struct tnode* head1, struct tnode* head2){
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;

    struct tnode *temp = head1;
    while(temp->next != head1){
        temp = temp->next;
    }

    temp->next = head2;
    temp = head2;
    while(temp->next != head2){
        temp = temp->next;
    }

    temp->next = head1;
    return head1;
}

/// podział listy na dwie listy cykliczne  - wartości parzyste i nieparzyste
/// Zwraca liczby nieparzyste, a w poczatkowej liscie zachowuje parzyste
/// Zbudowana podobnie jak funkcja usuwajaca elementy
struct tnode* div_list(struct tnode** head){
    int i = 0;
    int ilosc = 0;

    struct tnode *odd_head = NULL;
    struct tnode *poprzedni, *biezacy;

    if (*head == NULL){
        return NULL;
    }

    biezacy = *head;
    poprzedni = biezacy;

    while (poprzedni->next != *head){
        poprzedni = poprzedni->next;
        ilosc++;
    }

    while (i <= ilosc){
        if (biezacy->value % 2 == 1){
            if (biezacy->next != biezacy){
                poprzedni->next = biezacy->next;
            } else {
                poprzedni->next = NULL;
            }

            if (biezacy == *head) {
                *head = poprzedni->next;
            }

            odd_head = add_el(odd_head, biezacy);

            if (poprzedni != NULL) {
                biezacy = poprzedni->next;
            } else {
                biezacy = NULL;
            }
        } else {
            poprzedni = biezacy;
            biezacy  = biezacy->next;
        }

        i++;
    }
    return odd_head;
}

/// odwracanie listy w miejscu
void rev_list(struct tnode** head){
    struct tnode *odwrocona = NULL;
    while (*head) {
        struct tnode *next = (*head)->next;
        (*head)->next = odwrocona;
        odwrocona = *head;
        *head = next;
    }
    odwrocona = odwrocona->next;
    *head = odwrocona;
}

/// zwalnianie listy
void free_list(struct tnode** head_ptr){
    struct tnode *begin = *head_ptr;
    struct tnode *next_ptr = NULL;
    while (*head_ptr != NULL && (*head_ptr)->next != begin){
        next_ptr = (*head_ptr)->next;
//        printf("%d, ",(*head_ptr)->value);
        free(*head_ptr);
        *head_ptr = next_ptr;
    }
//    printf("%d\n",(*head_ptr)->value);
    free(*head_ptr);
}