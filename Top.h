//
// Created by xparh on 12/5/2021.
//

#ifndef OOP_VEZBE_10_1_TOP_H
#define OOP_VEZBE_10_1_TOP_H

#include "Figura.h"
#include "Polje.h"
#include "Greska.h"

class Top : public Figura {
public:
    Top(Boja boja, Polje poljeNaKomeSeNalazi) : Figura(boja, poljeNaKomeSeNalazi) {}
    char oznaka() const override {return 'T';}

    void pomeriNa(const Polje &p) override {
        if (!(p+this->polje)) throw GPogresanPotez();
        this->polje = p;
    }

    Figura *kopija() const override {
        return new Top(*this);
    }
};


#endif //OOP_VEZBE_10_1_TOP_H
