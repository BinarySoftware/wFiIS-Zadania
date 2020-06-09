#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef void (*free_fun)(void *);
typedef int (*list_list)(void *);//definicja funkcji wypisującej pamięć zaalokowaną w pojedynczym elemencie listy

typedef struct _listNode {
    void *data; //wskaźnik do alokowanej pamięci, pozwalającej na przechowywanie  wartości dowolnego typu
    struct _listNode *next; //wskaźnik do kolejnego elementu
} listNode; // struktura używana przez funkcje implementujące


typedef struct {//struktura opisująca listę
    int list_len;//ilość elementów w liście
    int el_size; //rozmiar elementu listy
    listNode *head; //wskaźnik do początku listy
    listNode *tail; //wskaźnik do końca listy
    free_fun freeFn; //funkcja zwalniająca pamięć usuwanego elementu
} list;

void list_new(list *list, int elementSize, free_fun free_free){
    assert(elementSize > 0);
    list->list_len = 0;
    list->el_size = elementSize;
    list->head = list->tail = NULL;
    list->freeFn = free_free;
}

//argumenty to: wskaźnik do listy oraz wskaźnik do wartości, którą ma  przechowywać nowotworzony element listy
void list_front(list *list, void *element){
    listNode *node = malloc(sizeof(listNode)); //tworzenie elementu listy
    node->data = malloc(list->el_size); //alokacja pamięci na wartość, która ma przechowywać element listy
    memcpy(node->data, element, list->el_size);// skopiowanie zawartości do zaalokowanej pamięci

    node->next = list->head;
    list->head = node;

    if(!list->tail) {
        list->tail = list->head;
    }

    list->list_len++;
}

void list_end(list *list, void *element){
    listNode *node = malloc(sizeof(listNode)); //tworzenie elementu listy
    node->data = malloc(list->el_size); //alokacja pamięci na wartość, która ma przechowywać element listy
    memcpy(node->data, element, list->el_size);// skopiowanie zawartości do zaalokowanej pamięci

    if (list->tail) {
        list->tail->next = node;
    }
    list->tail = node;
    node->next = NULL;

    if(!list->head) {
        list->head = list->tail;
    }


    list->list_len++;
}

listNode * list_first(list *list){
    if (list == NULL)
        return NULL;

    if (list->head == NULL)
        return NULL;

    listNode * temp = list->head;
    list->head = list->head->next;

    return temp;
}

listNode * list_last(list *list){
    if (list == NULL)
        return NULL;

    if (list->head == NULL)
        return NULL;

    listNode * temp = list->head;
    while (temp->next != list->tail){
        temp = temp->next;
    }

    listNode * last = list->tail;
    list->tail = temp;
    list->tail->next = NULL;
    return last;
}

int iterate_double(void *data);//wypisywanie double "doczepianych" do elementów listy
int iterate_string(void *data);//wypisywanie stringów "doczepianych" do elementów listy
void free_string(void *data);//zwalnianie pamieci na stringi "doczepiane" do elementów listy

void list_all(list *list, list_list iter_list){
    assert(iter_list != NULL);

    listNode *node = list->head;
    int result = 1;
    while(node != NULL && result) {
        result = iter_list(node->data);
        node = node->next;
    }
}

void list_free(list *list){
    listNode *current;
    while(list->head != NULL) {
        current = list->head;
        list->head = current->next;

        if(list->freeFn) { //np. dla alokowanych stringów
            list->freeFn(current->data);
        }

        free(current->data);//dla pamięci, nie alokowanej
        free(current);
    }
}

void list_double(){
    double numbers[] = { 7.4, 1.3, 14.5, 0.1, -1.0, 2.3, 1,2, 43.0, 2.0, -4.7, 5.8 };

    int i;
    list list_d;
    list_new(&list_d, sizeof(double), NULL);

    for(i = 0; i <= 10; i++) {
        list_front(&list_d, numbers+i);
    }

    for(i = 0; i <= 10; i++) {
        list_end(&list_d, numbers+i);
    }

    list_all(&list_d, iterate_double);
    //testowanie pozostałych funkcji

    printf("Removing first:\n");
    listNode * first = list_first(&list_d);
    list_all(&list_d, iterate_double);
    printf("First:\n");
    iterate_double(first->data);

    printf("Removing last:\n");
    listNode * last = list_last(&list_d);
    list_all(&list_d, iterate_double);
    printf("Last:\n");
    iterate_double(last->data);
    list_free(&list_d);

    free(first->data);
    free(last->data);
    free(first);
    free(last);
    printf("Successfully freed  numbers...\n");
}

void list_strings(){
    int numNames = 5;
    const char *names[] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"};

    int i;
    list list_s;
    list_new(&list_s, sizeof(char *), free_string);

    char *name;
    for(i = 0; i < numNames; i++) {
        name = strdup(names[i]);//Funkcja strdup() zwraca wskaźnik do nowego łańcucha, który stanowi kopię łańcucha s. Pamięć dla nowego łańcucha jest przydzielana za pomocą malloc() i może być zwolniona za pomocą free().
        list_front(&list_s, &name);
    }

    for(i = 0; i < numNames; i++) {
        name = strdup(names[i]);
        list_end(&list_s, &name);
    }

    list_all(&list_s, iterate_string);
    //testowanie pozostałych funkcji
    list_free(&list_s);
    printf("Successfully freed %d strings...\n", numNames);
}

int iterate_double(void *data){
    if (data == NULL ) return 0;
    printf("Found value: %f\n", *(double *)data);
    return 1;
}

int iterate_string(void *data){
    if (data == NULL ) return 0;
    printf("Found value: %s\n", *(char **)data);
    return 1;
}

void free_string(void *data){
    char * str = *(char **)data;
    free(str);
}

int main(int argc, char *argv[]){
    list_double();
    list_strings();
} 