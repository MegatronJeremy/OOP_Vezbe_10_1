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
    Figura *figure[8][8];
    Figura::Boja naPotezu = Figura::Boja::BELA;

public:
    Sah() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                figure[i][j] = nullptr;
            }
        }
    }

    Figura *&operator[](const Polje &p) {
        return figure[p.dohvKolonu()-'A'][p.dohvRed() - 1];
    }

    const Figura *&operator[](const Polje &p) const {
        return const_cast<const Figura *&>(const_cast<Sah &>(*this)[p]);
    }

    Sah &operator+=(Figura &f) {
        if ((*this)[f.dohvPolje()] != nullptr) throw GZauzetoPolje();
        (*this)[f.dohvPolje()] = f.kopija();

        return *this;
    }

    void pomeri(const Polje &sa, const Polje &na) {
        Figura *f = (*this)[sa];
        if (f == nullptr) throw GNemaFigure();

        if (f->dohvBoju() != naPotezu) throw GIgracNijeNaPotezu();

        Figura *fna = (*this)[na];
        if (fna != nullptr) {
            if (fna->dohvBoju() == f->dohvBoju()) throw GPogresanPotez();
        }

        f->pomeriNa(na);

        if (fna != nullptr) {
            delete (*this)[na];
        }
        (*this)[na] = f;
        (*this)[sa] = nullptr;

        naPotezu = naPotezu == Figura::BELA ? Figura::CRNA : Figura ::BELA;
    }

    friend ostream &operator<<(ostream &os, const Sah &s) {
        for (int i = 8; i > 0; i--) {
            os << "\033[1;43m " << i << " \033[0m";
            for (char j = 'A'; j <= 'H'; j++) {
                if ((i+j) % 2 == 0) os << "\033[1;40m";
                else os << "\033[1;47m";

                Polje p(j, i);
                const Figura *f = s[p];
                bool bela = true;
                char figura = ' ';

                if (f != nullptr) {
                    bela = f->dohvBoju() == Figura::BELA;
                    figura = f->oznaka();
                }

                if (bela) os << "\033[1;37m";
                else os << "\033[1;31m";
                os << " " << figura << " \033[0m";
            }
            os << endl;
        }
        os << "\033[1;43m   \033[0m";
        for (char j = 'A'; j <= 'H'; j++) {
            os << "\033[1;43m " << j << " \033[0m";
        }
        return os;
    }
};


#endif //OOP_VEZBE_10_1_SAH_H
