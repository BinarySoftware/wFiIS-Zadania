//
// Created by Maciej Mikołajek on 02/06/2020.
//

#include "cycle.h"

int main() {
    struct tnode *pusta = NULL;
    printf("Pusta lista");
    print_list(pusta);

    struct tnode *jedenElement = NULL;
    struct tnode* next_elem;
    next_elem = malloc(sizeof(struct tnode));
    next_elem->value = 1;
    jedenElement = add_el(jedenElement, next_elem);
    printf("lista 1 el");
    print_list(jedenElement);

    struct tnode* wieloElementowa = NULL;
    next_elem = malloc(sizeof(struct tnode));
    next_elem->value = 3;
    wieloElementowa = add_el(wieloElementowa, next_elem);
    for(int i=0; i<5; i++){
        next_elem = malloc(sizeof(struct tnode));
        next_elem->value = i*2;
        wieloElementowa = add_el(wieloElementowa, next_elem);
    }
    for(int i=0; i<3; i++){
        next_elem = malloc(sizeof(struct tnode));
        next_elem->value = 3;
        wieloElementowa = add_el(wieloElementowa, next_elem);
    }
    for(int i=15; i<20; i++){
        next_elem = malloc(sizeof(struct tnode));
        next_elem->value = i;
        wieloElementowa = add_el(wieloElementowa, next_elem);
    }
    printf("Wieloelementowa");
    print_list(wieloElementowa);
    printf("Usuwanie '3'\n");
    del_el(&wieloElementowa, 3);
    printf("Wieloelementowa");
    print_list(wieloElementowa);

    struct tnode* wieloElementowa2 = NULL;
    for(int i=0; i<5; i++){
        next_elem = malloc(sizeof(struct tnode));
        next_elem->value = 20+ i;
        wieloElementowa2 = add_el(wieloElementowa2, next_elem);
    }
    printf("Wieloelementowa2");
    print_list(wieloElementowa2);
    struct tnode * concat = add_list(wieloElementowa, wieloElementowa2);
    printf("Konkatenowana");
    print_list(concat);

    struct tnode * nieparzysta = div_list(&concat);
    printf("Nieparzysta");
    print_list(nieparzysta);
    printf("Parzysta");
    print_list(concat);

    printf("Odwrocona");
    rev_list(&concat);
    print_list(concat);

    printf("Zwalnianie\n");
    free_list(&concat);
    free_list(&nieparzysta);
    free_list(&jedenElement);
    return 0;
}
