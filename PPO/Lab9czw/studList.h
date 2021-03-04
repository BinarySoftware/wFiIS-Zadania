#pragma once

#include "element.h"

class StudList{
    private:
        char _listName[10];
        Element * _head;
        Element * _tail;
    public:
        StudList(const char * x);
        ~StudList();
        void append(const char * x);
        void append(Element * x);
        Element * getHead();
        Element * getTail();
        Element * getLast();
        char * getName() const;
        bool isEmpty() const;
        void print() const;
        void clearList();
        void removeLast();
};