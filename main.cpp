#include <string>
#include <exception>
#include <iostream>

#include "Polje.h"
#include "Figura.h"
#include "Top.h"
#include "Lovac.h"
#include "Skakac.h"
#include "Sah.h"

using namespace std;

int main() {

    try {
        Polje a4('A', 4);
        Polje b3('B', 3);
        Polje d4('D', 4);

        Top t1(Figura::BELA, a4);
        Lovac l1(Figura::CRNA, b3);
        Skakac s1(Figura::BELA, d4);

        Sah sah;

        sah += t1;
        sah += l1;
        sah += s1;

        cout << sah;

        while(true) {
            try {
                char kolona;
                int red;

                cout << endl << "Unesite kolonu i red polja sa koga pomerate figuru: ";
                cin >> kolona >> red;

                Polje sa(kolona, red);

                cout << "Unesite kolonu i red polja na koga pomerate figuru: ";
                cin >> kolona >> red;

                Polje na(kolona, red);

                sah.pomeri(sa, na);

                cout << "\x1B[2J\x1B[H"; // cisti konzolu
                cout << sah;
            }
            catch (exception &e) {
                cout << e.what() << endl;
            }
        }
    }
    catch (exception &e) {
        cout << e.what() << endl;
    }
    cout << endl << "Kraj programa..." << endl << endl;

    return 0;
}
