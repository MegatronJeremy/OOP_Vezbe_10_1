//
// Created by xparh on 12/5/2021.
//

#ifndef OOP_VEZBE_10_1_DAMA_H
#define OOP_VEZBE_10_1_DAMA_H

#include "Figura.h"
#include "Polje.h"
#include "Greska.h"

class Dama : public Figura {
public:
    Dama(Boja boja, Polje poljeNaKomeSeNalazi) : Figura(boja, poljeNaKomeSeNalazi) {}
    char oznaka() const override {return 'D';}

    void pomeriNa(const Polje &p) override {
        if (!(p+this->polje)&&!(p/this->polje)) throw GPogresanPotez();
        this->polje = p;
    }

    Figura *kopija() const override {
        return new Dama(*this);
    }
};


#endif //OOP_VEZBE_10_1_DAMA_H
