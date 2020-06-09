#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// pojedynczy element tworzacy liste
struct tnode {
    int value;
    struct tnode *next;
    struct tnode *prev;
};

/// wypisywanie listy
void print_list(struct tnode*);

/// dodawanie elementu do listy na początku
struct tnode* add_first(struct tnode* head, struct tnode* el);

/// dodawanie elementu do listy na końcu
struct tnode* add_last(struct tnode* head, struct tnode* el);

/// wyciąganie elementu z listy (wczytanie wartości klucza do wyboru elementu),
/// jeżeli mamy kilka elementów o podanym kluczu zwracamy pierwszy
struct tnode* del_el(struct tnode** head, int var);

/// dokładanie w porządku rosnącym
void add_sort(struct tnode** head1, struct tnode* el);

/// podział listy na dwie listy
/// wartości parzyste i nieparzyste z wykorzystaniem
/// wcześniej zaimplementowaych funkcji
struct tnode* div_list(struct tnode** head);

/// implementacja rekurencyjnego algorytmu szybkiego sortowania na liscie
/// dwukierunkowej z wykorzystaniem wcześniej zaimplementowaych funkcji
void sort(struct tnode** head);

/// zwalnianie listy
void free_list(struct tnode**);

int rand_int(int a, int b) {
    return (a + rand()%(b-a+1));
}

int main() {
    struct tnode * head = NULL;
    printf("Pusta lista:\n");
    print_list(head);

    struct tnode* next_elem;
    for(int i=0; i<5; i++){
        next_elem = malloc(sizeof(struct tnode));
        next_elem->value = i;
        head = add_first(head, next_elem);
    }
    printf("Lista po dodaniu na poczatek:\n");
    print_list(head);

    for(int i=0; i<5; i++){
        next_elem = malloc(sizeof(struct tnode));
        next_elem->value = i;
        head = add_last(head, next_elem);
    }
    printf("Lista po dodaniu na koniec:\n");
    print_list(head);

    struct tnode * deleted2 = del_el(&head,2);
    printf("Lista po usunieciu 2:\n");
    print_list(head);
    printf("element:\n");
    print_list(deleted2);

    free_list(&head);
    free_list(&deleted2);

    srand(time(0));
    struct tnode * head2 = NULL;
    for(int i=0; i<8; i++){
        next_elem = malloc(sizeof(struct tnode));
        next_elem->value = rand_int(1,20);
        add_sort(&head2, next_elem);
    }
    printf("Lista 2 po dodaniu uporzadkowanym:\n");
    print_list(head2);

    struct tnode * nhead2 = div_list(&head2);
    printf("Lista 2 - parzyste:\n");
    print_list(head2);
    printf("Lista 2 - nieparzyste:\n");
    print_list(nhead2);

    free_list(&nhead2);
    free_list(&head2);

    struct tnode * head3 = NULL;
    for(int i=0; i<8; i++){
        next_elem = malloc(sizeof(struct tnode));
        next_elem->value = rand_int(1,20);
        head3 = add_last(head3, next_elem);
    }
    printf("Lista 2 przed sortem:\n");
    print_list(head3);
    sort(&head3);
    printf("Lista 2 po sorcie:\n");
    print_list(head3);
    free_list(&head3);
    return 0;
}


void print_list(struct tnode *head){
    printf("NULL ");
    while (head != NULL){
        printf("<-> ['%d'] ",head->value);
        head = head->next;
    }
    printf("<-> NULL\n");
}

struct tnode * add_first(struct tnode *head, struct tnode* el){
    el->next = head;
    if (head != NULL){
        head->prev = el;
    }
    el->prev = NULL;
    return el;
}

struct tnode * add_last(struct tnode *head, struct tnode* el){
    if (head != NULL){
        struct tnode *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        el->prev = temp;
        el->next = NULL;
        temp->next = el;
    } else {
        el->prev = NULL;
        el->next = NULL;
        head = el;
    }
    return head;
}

struct tnode * del_el(struct tnode** head, int var){
    if (*head == NULL)
        return NULL;

    struct tnode* current = *head;

    while (current != NULL) {
        if (current->value == var) {
            if (*head == current){
                *head = current->next;
            }

            if (current->prev != NULL) {
                current->prev->next = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            current->next = NULL;
            current->prev = NULL;

            return current;
        } else {
            current = current->next;
        }
    }

    return NULL;
}

void add_sort(struct tnode** head1, struct tnode* el){
    el->prev = NULL;
    el->next = NULL;

    if (*head1 != NULL){
        if ((*head1)->value > el->value) {
            el->next = *head1;
            (*head1)->prev = el;
            *head1 = el;
            return;
        }

        struct tnode *temp = *head1;
        while(temp->next != NULL){
            if (temp->next->value > el->value) {
                el->next = temp->next;
                el->prev = temp;
                temp->next = el;
                el->next->prev = el;
                return;
            }
            temp = temp->next;
        }
        temp->next = el;
        el->prev = temp;
    } else {
        *head1 = el;
    }
}

struct tnode* div_list(struct tnode** head){
    struct tnode *odd_head = NULL;

    if (*head == NULL)
        return NULL;

    struct tnode* current = *head;
    struct tnode* next;

    while (current != NULL) {
        if (current->value % 2 == 1) {
            next = current->next;
            current = del_el(head, current->value);
            odd_head = add_last(odd_head, current);
            current = next;
        } else {
            current = current->next;
        }
    }

    return odd_head;
}

void swap (int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct tnode *lastNode(struct tnode *head){
    while (head && head->next){
        head = head->next;
    }
    return head;
}

struct tnode* partition(struct tnode *head, struct tnode *last){
    int x = last->value;
    struct tnode *i = head->prev;

    for (struct tnode *j = head; j != last; j = j->next){
        if (j->value <= x){
            i = (i == NULL) ? head : i->next;

            swap(&(i->value), &(j->value));
        }
    }
    i = (i == NULL) ? head : i->next;
    swap(&(i->value), &(last->value));
    return i;
}

void _quickSort(struct tnode* head, struct tnode *last){
    if (last != NULL && head != last && head != last->next){
        struct tnode *part = partition(head, last);
        _quickSort(head, part->prev);
        _quickSort(part->next, last);
    }
}

void sort(struct tnode** head) {
    struct tnode *last = lastNode(*head);
    _quickSort(*head, last);
}

void free_list(struct tnode **list){
    struct tnode *next_ptr = NULL;
    while (*list != NULL){
        next_ptr = (*list)->next;
        free(*list);
        *list = next_ptr;
    }
    free(*list);
}