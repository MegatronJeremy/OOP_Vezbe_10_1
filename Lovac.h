//
// Created by xparh on 12/5/2021.
//

#ifndef OOP_VEZBE_10_1_LOVAC_H
#define OOP_VEZBE_10_1_LOVAC_H


#include "Figura.h"
#include "Polje.h"
#include "Greska.h"

class Lovac : public Figura {
public:
    Lovac(Boja boja, Polje poljeNaKomeSeNalazi) : Figura(boja, poljeNaKomeSeNalazi) {}
    char oznaka() const override {return 'L';}

    virtual void pomeriNa(const Polje &p) override {
        if (!(p/this->polje)) throw GPogresanPotez();
        this->polje = p;
    }

    Figura *kopija() const override {
        return new Lovac(*this);
    }
};

#endif //OOP_VEZBE_10_1_LOVAC_H
