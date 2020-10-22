#include <stdlib.h>
#include <stdio.h>

///
/// Struktura tworzaca jeden element listy jednokierunkowej
///
struct tnode{
    int value;
    struct tnode *next;
};

///
/// Funkcja zwalniajaca pamiec zajmowana przez 2 listy jednokierunkowe
///
void zwolnij(struct tnode *list_1, struct tnode *list_2){
    struct tnode *node = list_1;
    struct tnode *next_ptr = NULL;
    while (node != NULL && node->value != 0){
        next_ptr = node->next;
        free(node);
        node = next_ptr;
    }

    node = list_2;
    next_ptr = NULL;
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
        printf("-> ['%d'] ",head->value);
        head = head->next;
    }
    printf("-> NULL\n");
}

void wypisz_adr(struct tnode *head){
    while (head != NULL){
        printf("-> ['%p'] ",head);
        head = head->next;
    }
}

///
/// Funkcja dodajaca element na koniec listy jednokierunkowej
///
struct tnode * dodaj_na_koniec(struct tnode *head, int val){
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

void dodaj_na_koniec_dwoch(struct tnode **L_1 , struct tnode **L_2, int val){
    struct tnode *new_last_elem = malloc(sizeof(struct tnode));
    new_last_elem->value=val;
    new_last_elem->next=NULL;

    if (*L_1 != NULL){
        struct tnode *temp = *L_1;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_last_elem;
    } else {
        *L_1 = new_last_elem;
    }

    if (*L_2 != NULL){
        struct tnode *temp = *L_2;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_last_elem;
    } else {
        *L_2 = new_last_elem;
    }
}

///
/// czytanie wejscia i tworzenie 2 tablic
///
void reader(struct tnode **L_1, struct tnode **L_2) {
    int a;
    while (1){
        printf("Podaj l. naturalna: ");
        scanf("%d",&a);
        if (a > 20) {
            break;
        } else if (a == 0) {
            dodaj_na_koniec_dwoch(L_1, L_2, a);
        } else if (a % 2 == 1) {
            (*L_2) = dodaj_na_koniec((*L_2), a);
        } else if (a % 2 == 0) {
            (*L_1) = dodaj_na_koniec((*L_1), a);
        }
    }
}

int czy_wsp_element(struct tnode* L_1, struct tnode* L_2){
    while(L_1 != NULL){
        struct tnode* temp = L_2;
        while(temp != NULL){
            if(temp == L_1)
                return 1;
            else
                temp = temp->next;
        }
        L_1 = L_1->next;
    }
    return 0;
}

///
/// MAIN
///
int main(int argc, char** argv) {
    struct tnode *L_1 = NULL;
    struct tnode *L_2 = NULL;

    reader(&L_1, &L_2);

    printf("L_1 ");
    wypisz(L_1);
    printf("L_2 ");
    wypisz(L_2);

    printf("\nAdresy - dowód połączenia list przy 0:");
    printf("\nL_1 ");
    wypisz_adr(L_1);
    printf("\nL_2 ");
    wypisz_adr(L_2);

    if(czy_wsp_element(L_1, L_2)){
        printf("\nListy maja wspolny element\n");
    } else {
        printf("\nListy nie maja wspolnego elementu\n");
    }

    zwolnij(L_1, L_2);
    return 0;
}