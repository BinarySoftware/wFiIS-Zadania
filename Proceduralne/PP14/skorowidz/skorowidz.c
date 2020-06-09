//
// Created by Maciej Mikołajek on 02/06/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode{
    char text[64];
    int il_wystapien;
    struct tnode *next;
};

void zwolnij(struct tnode *list){
    struct tnode *node = list;
    struct tnode *next_ptr = NULL;
    while (node != NULL){
        next_ptr = node->next;
        free(node);
        node = next_ptr;
    }
}

void wypisz(struct tnode *head){
    while (head != NULL){
        printf("%20s : %d\n",head->text, head->il_wystapien);
        head = head->next;
    }
}

void dodaj_uporzadkowane(struct tnode **head, char * val){
    struct tnode *new_elem = malloc(sizeof(struct tnode));
    strcpy(new_elem->text, val);
    new_elem->il_wystapien = 1;

    if (*head == NULL) {
        new_elem->next = *head;
        *head = new_elem;
    } else {
        if (strcmp((*head)->text, val) > 0) {
            new_elem->next = *head;
            *head = new_elem;
            return;
        }

        struct tnode *temp = *head;
        while(temp->next != NULL){
            if (strcmp(temp->next->text, val) > 0)  {
                new_elem->next = temp->next;
                temp->next = new_elem;
                return;
            } else if (strcmp(temp->next->text, val) == 0)  {
                temp->next->il_wystapien++;
                free(new_elem);
                return;
            }
            temp = temp->next;
        }

        new_elem->next = NULL;
        temp->next = new_elem;
    }
}

int main() {
    struct tnode *skorowidz = NULL;

    char * filename = "plik_wejsciowy.txt";
    FILE* filePointer;
    char buffer[BUFSIZ];

    filePointer = fopen(filename, "r");

    while(!feof(filePointer)){
        fscanf(filePointer,"%s",buffer);
        dodaj_uporzadkowane(&skorowidz, buffer);
    }

    fclose(filePointer);

    wypisz(skorowidz);
    zwolnij(skorowidz);
    return 0;
}
