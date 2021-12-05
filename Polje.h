//
// Created by xparh on 12/5/2021.
//

#ifndef OOP_VEZBE_10_1_POLJE_H
#define OOP_VEZBE_10_1_POLJE_H

#include "Greska.h"
#include <iostream>

using namespace std;

class Polje {
    char kolona;
    int red;
public:
    Polje(char kolona, int red) {
        if (red < 1 || red > 8 || kolona > 'H' || kolona < 'A')
            throw GPogresnoPolje();
        this->kolona = kolona;
        this->red = red;
    }

    char dohvKolonu() const {return kolona;}
    int dohvRed() const {return red;}

    friend ostream &operator<<(ostream &os, const Polje &p) {
        return os << p.kolona << p.red;
    }

    friend bool operator==(const Polje &p1, const Polje &p2) {
        return p1.red == p2.red && p1.kolona == p2.kolona;
    }

    friend bool operator+(const Polje &p1, const Polje &p2) {
        return p1.red == p2.red || p1.kolona == p2.kolona;
    }

    friend bool operator/(const Polje &p1, const Polje &p2) {
        return abs(p1.red - p2.red) == abs(p1.kolona - p2.kolona);
    }

};


#endif //OOP_VEZBE_10_1_POLJE_H
