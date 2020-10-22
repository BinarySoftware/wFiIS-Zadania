//
// Created by Maciej Mikołajek on 02/06/2020.
//

#ifndef CYCLE_CYCLE_H
#define CYCLE_CYCLE_H

#include <stdio.h>
#include <stdlib.h>

/// Podstawowy element listy
struct tnode {
    int value;
    struct tnode *next;
};

/// wypisywanie listy
void print_list(struct tnode*);

/// dodawanie elementu do listy
struct tnode* add_el(struct tnode* head, struct tnode* el);

/// usuwanie elementu z listy, jeżeli mamy kilka elementów
/// o podanym kluczu usuwamy wszystkie
void del_el(struct tnode** head, int var);

/// łączenie dwóch list cyklicznych w jedną
struct tnode* add_list(struct tnode* head1, struct tnode* head2);

/// podział listy na dwie listy cykliczne  - wartości parzyste i nieparzyste
struct tnode* div_list(struct tnode** head);

/// odwracanie listy w miejscu
void rev_list(struct tnode**);

/// zwalnianie listy
void free_list(struct tnode**);

#endif //CYCLE_CYCLE_H
