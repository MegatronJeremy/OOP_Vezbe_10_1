//
// Created by xparh on 12/5/2021.
//

#ifndef OOP_VEZBE_10_1_GRESKA_H
#define OOP_VEZBE_10_1_GRESKA_H

#include <exception>

using namespace std;

class GPogresnoPolje: public exception {
public:
    const char *what() const noexcept override {
        return "Greska: Pogresno zadato polje.";
    }
};

class GPogresanPotez: public exception {
public:
    const char *what() const noexcept override {
        return "Greska: Pogresan potez.";
    }
};

class GZauzetoPolje: public exception {
public:
    const char *what() const noexcept override {
        return "Greska: Zauzeto polje.";
    }
};

class GNemaFigure: public exception {
public:
    const char *what() const noexcept override {
        return "Greska: Nema figure.";
    }
};

class GIgracNijeNaPotezu: public exception {
public:
    const char *what() const noexcept override {
        return "Greska: Igrac nije na potezu.";
    }
};
#endif //OOP_VEZBE_10_1_GRESKA_H
