//
// Created by xparh on 12/5/2021.
//

#ifndef OOP_VEZBE_10_1_SAH_H
#define OOP_VEZBE_10_1_SAH_H

#include "Figura.h"
#include "Greska.h"
#include <iostream>

using namespace std;

class Sah {
    Figura ***figure;
    Figura::Boja naPotezu = Figura::Boja::BELA;

    friend void swap(Sah &s1, Sah &s2);

public:
    Sah();
    Sah(const Sah &s);
    Sah(Sah &&s) noexcept ;
    ~Sah();

    Sah &operator=(Sah s);

    Figura *&operator[](const Polje &p) {
        return figure[p.dohvKolonu()-'A'][p.dohvRed() - 1];
    }

    const Figura *&operator[](const Polje &p) const {
        return const_cast<const Figura *&>(const_cast<Sah &>(*this)[p]);
    }

    Sah &operator+=(Figura &f);

    void operator()(const Polje &sa, const Polje &na);

    friend ostream &operator<<(ostream &os, const Sah &s);
};


#endif //OOP_VEZBE_10_1_SAH_H
