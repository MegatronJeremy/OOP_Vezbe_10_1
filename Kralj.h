//
// Created by xparh on 12/5/2021.
//

#ifndef OOP_VEZBE_10_1_KRALJ_H
#define OOP_VEZBE_10_1_KRALJ_H

#include "Figura.h"
#include "Polje.h"
#include "Greska.h"

class Kralj : public Figura {
public:
    Kralj(Boja boja, Polje poljeNaKomeSeNalazi) : Figura(boja, poljeNaKomeSeNalazi) {}
    char oznaka() const override {return 'K';}

    void pomeriNa(const Polje &p) override {
        if (!(abs(p.dohvRed() - polje.dohvRed()) + abs(p.dohvKolonu() - polje.dohvKolonu()) == 1 ||
            abs(p.dohvRed() - polje.dohvRed()) + abs(p.dohvKolonu() - polje.dohvKolonu()) == 2 && p/polje))
            throw GPogresanPotez();
        this->polje = p;
    }

    Figura *kopija() const override {
        return new Kralj(*this);
    }
};


#endif //OOP_VEZBE_10_1_KRALJ_H
