#include "element.h"
#include <iostream>
#include <string.h>

Element::Element(const char * x){
    strcpy(this->_name, x);
}

Element::~Element(){
    std::cout << "Destruktor Element: " << getName() << std::endl;
}

char * Element::getName(){
    return this->_name;
}

void Element::printName(){
    std::cout << getName();
}

Element * Element::getNext(){
    return this->_next;
}

void Element::setNext(Element * e){
    this->_next = e;
}