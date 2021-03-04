#pragma once

#include "Prezent.h"

class Worek {
    public:
        void WypiszZawartosc();
        void UsunPrezentNumer(int p);
        void Wloz(Prezent p);
    private:
        Prezent * head = nullptr;
};