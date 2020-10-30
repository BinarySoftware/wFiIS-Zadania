#include "lab05.h"

#include <iostream>
#include <cstring>

void prepare(List * l){
  l->head = NULL;
}

void push_back(List * l, const char * buffer){
  Node * current = l->head;
  while (current != NULL && current->next != NULL)
    current = current->next;

  Node * n = new(Node);
  strcpy(n->data, buffer);
  n->next = NULL;
  n->previous = current;

  if (current == NULL)
    l->head = n;
  else 
    current->next = n;
}

void push_front(List * l, const char * buffer){
  Node * n = new(Node);
  strcpy(n->data, buffer);
  n->next = l->head;
  n->previous = NULL;
  l->head->previous = n;
  l->head = n;
}

int empty(const List * l){
  if (l->head == NULL)
    return 1;
  return 0;
}

void dump(const List * l){
  Node * current = l->head;
  while (current != NULL){
    std::cout << current->data << " ";
    current = current->next;
  }
}

void clear(List * l){
  Node * current = l->head;
  while (current != NULL){
    Node * temp = current;
    current = current->next;
    delete temp;
  }
  l->head = NULL;
}
