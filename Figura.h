//
// Created by xparh on 12/5/2021.
//

#ifndef OOP_VEZBE_10_1_FIGURA_H
#define OOP_VEZBE_10_1_FIGURA_H

#include "Polje.h"
#include <iostream>

using namespace std;

class Figura {
public:
    enum Boja{BELA, CRNA};
protected:
    Boja boja;
    Polje polje;
public:
    virtual ~Figura() = default;

    Figura(Boja boja, Polje poljeNaKomeSeNalazi) : polje(poljeNaKomeSeNalazi) {
        this->boja = boja;
    }
    virtual char oznaka() const = 0;
    virtual void pomeriNa(const Polje &p) = 0;
    virtual Figura *kopija() const = 0;
    friend ostream &operator<<(ostream &os, const Figura &f) {
        return os << f.oznaka() << f.polje;
    }

    Boja dohvBoju() const {return boja;}
    Polje dohvPolje() const {return polje;}
};


#endif //OOP_VEZBE_10_1_FIGURA_H
