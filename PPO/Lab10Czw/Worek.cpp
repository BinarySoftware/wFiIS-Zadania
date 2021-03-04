#include "Worek.h"

#include <iostream>

void Worek::WypiszZawartosc(){
    std::cout << "=== Zawartosc worka ===" << std::endl;
    Prezent * temp = head;
    int current    = 1;
    while (temp != nullptr) {
        std::cout << current << ". ";
        temp->Wypisz();
        current++;
        temp = temp->next;
    }
}
void Worek::UsunPrezentNumer(int p){
    int current    = 1;
    Prezent * temp = head;
    if (p == 1) {
        head = head->next;
        return;
    }
    while (temp != nullptr) {
        if (current+1 == p && temp->next != nullptr){
            temp->next = temp->next->next;
            return;
        }
        current++;
        temp = temp->next;
    }
}
void Worek::Wloz(Prezent p){
    if (head == nullptr) {
        head = &p;
    } else {
        Prezent * temp = head;
        while (temp->next != nullptr) { temp = temp->next; }
        temp->next = &p;
    }
}