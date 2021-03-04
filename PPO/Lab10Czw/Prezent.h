#pragma once

class Prezent {
    public:
        Prezent(int wartosc) : next(nullptr), _wartosc(wartosc) {};
        ~Prezent(){};
        void Wypisz();
        Prezent * next;
    private:
        int _wartosc;
};