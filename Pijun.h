//
// Created by xparh on 12/5/2021.
//

#ifndef OOP_VEZBE_10_1_PIJUN_H
#define OOP_VEZBE_10_1_PIJUN_H


#include "Figura.h"
#include "Polje.h"
#include "Greska.h"

class Pijun : public Figura {
private:
    bool hasMoved = false;
public:
    Pijun(Boja boja, Polje poljeNaKomeSeNalazi) : Figura(boja, poljeNaKomeSeNalazi) {}
    char oznaka() const override {return 'P';}

    void pomeriNa(const Polje &p) override {
        if (!(polje.dohvKolonu() == p.dohvKolonu() &&
        (boja == BELA && polje.dohvRed() + 1 == p.dohvRed() || boja == CRNA && polje.dohvRed() - 1 == p.dohvRed()) ||
        !hasMoved && (boja == BELA && polje.dohvRed() + 2 == p.dohvRed() || boja == CRNA && polje.dohvRed() - 2 == p.dohvRed())))
            throw GPogresanPotez();
        this->polje = p;
        hasMoved = true;
    }

    Figura *kopija() const override {
        return new Pijun(*this);
    }
};

#endif //OOP_VEZBE_10_1_PIJUN_H
