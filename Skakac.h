//
// Created by xparh on 12/5/2021.
//

#ifndef OOP_VEZBE_10_1_SKAKAC_H
#define OOP_VEZBE_10_1_SKAKAC_H


#include "Figura.h"
#include "Polje.h"
#include "Greska.h"

class Skakac : public Figura {
public:
    Skakac(Boja boja, Polje poljeNaKomeSeNalazi) : Figura(boja, poljeNaKomeSeNalazi) {}
    char oznaka() const override {return 'S';}

    void pomeriNa(const Polje &p) override {
        if (!(abs(p.dohvRed() - this->polje.dohvRed()) + abs(p.dohvKolonu() - this->polje.dohvKolonu()) == 3
            && p.dohvKolonu() != this->polje.dohvKolonu() && p.dohvRed() != this->polje.dohvRed())) throw GPogresanPotez();
        this->polje = p;
    }

    Figura *kopija() const override {
        return new Skakac(*this);
    }
};

#endif //OOP_VEZBE_10_1_SKAKAC_H
