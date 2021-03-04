#pragma once

class Element{
    private:
        char _name[10];
        Element * _next;
    public:
        Element(const char * x);
        ~Element();
        char * getName();
        void printName();
        Element * getNext();
        void setNext(Element * e);
};