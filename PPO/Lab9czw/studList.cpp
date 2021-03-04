#include "studList.h"
#include "element.h"
#include <iostream>
#include <string.h>

StudList::StudList(const char * x){
    strcpy(this->_listName, x);
}

StudList::~StudList(){
    std::cout << "Destruktor StudList: " << getName() << std::endl;
}

void StudList::append(const char * x){
    Element * elem = new Element(x);
    StudList::append(elem);
}

void StudList::append(Element * x){
    if (this->isEmpty()) {
        this->_head = x;
        this->_tail = x;
        this->_tail->setNext(NULL);
        return;
    }
    this->_tail->setNext(x);
    this->_tail = x;
    this->_tail->setNext(NULL);
}

Element * StudList::getHead() {
    return this->_head;
}

Element * StudList::getTail(){
    return this->_tail;
}

Element * StudList::getLast(){
    Element * temp = this->getHead();
    this->_head = temp->getNext();
    return temp;
}

char * StudList::getName() const {
    return (char *) this->_listName;
}

bool StudList::isEmpty() const {
    return this->_head == NULL;
}

void StudList::print() const {
    std::cout << this->getName() << " = [ ";
    Element * temp = this->_head;
    while (temp != NULL){
        std::cout << temp->getName() << " ";
        temp = temp->getNext();
    }
    std::cout << "]" << std::endl;
}

void StudList::clearList() {
    while (this->_head != NULL){
       removeLast();
    }
    
}

void StudList::removeLast() {
    if (this->_head != NULL){
        Element * temp = this->getHead();
        this->_head = temp->getNext();
        temp->~Element();
        delete[] temp->getName();
    }
}
