//
// Created by xparh on 12/5/2021.
//

#include "Sah.h"
#include "Kralj.h"
#include "Dama.h"
#include "Lovac.h"
#include "Pijun.h"
#include "Skakac.h"
#include "Top.h"

void swap(Sah &s1, Sah &s2) {
    std::swap(s1.figure, s2.figure);
    std::swap(s1.naPotezu, s2.naPotezu);
}

Sah::Sah(const Sah &s) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            figure[i][j] = s.figure[i][j]->kopija();
        }
    }
    naPotezu = s.naPotezu;
}

Sah::Sah(Sah &&s) noexcept {
    figure = s.figure;
    naPotezu = s.naPotezu;
    s.figure = nullptr;
}

Sah::Sah() {
    figure = new Figura**[8];
    for (int i = 0; i < 8; i++) {
        figure[i] = new Figura*[8];
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == 0 || i == 7) {
                switch (j) {
                    case 0: case 7:
                        figure[j][i] = new Top((i == 0 ? Figura::BELA : Figura::CRNA), Polje(char('A' + j), i+1));
                        break;
                    case 1: case 6:
                        figure[j][i] = new Skakac((i == 0 ? Figura::BELA : Figura::CRNA), Polje(char('A' + j), i+1));
                        break;
                    case 2: case 5:
                        figure[j][i] = new Lovac((i == 0 ? Figura::BELA : Figura::CRNA), Polje(char('A' + j), i+1));
                        break;
                    case 3:
                        figure[j][i] = new Dama((i == 0 ? Figura::BELA : Figura::CRNA), Polje(char('A' + j), i+1));
                        break;
                    case 4:
                        figure[j][i] = new Kralj((i == 0 ? Figura::BELA : Figura::CRNA), Polje(char('A' + j), i+1));
                        break;
                    default:
                        break;
                }
            } else if (i == 1 || i == 6) {
                figure[j][i] = new Pijun((i==1 ? Figura::BELA : Figura::CRNA), Polje(char('A' + j), i+1));
            } else {
                figure[j][i] = nullptr;
            }
        }
    }
}

Sah::~Sah() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            delete figure[i][j];
        }
        delete[] figure[i];
    }
    delete[] figure;
}

Sah &Sah::operator+=(Figura &f) {
    if ((*this)[f.dohvPolje()] != nullptr) throw GZauzetoPolje();
    (*this)[f.dohvPolje()] = f.kopija();

    return *this;
}

void Sah::operator()(const Polje &sa, const Polje &na) {
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

ostream &operator<<(ostream &os, const Sah &s) {
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

Sah &Sah::operator=(Sah s) {
    swap(s, *this);
    return *this;
}
