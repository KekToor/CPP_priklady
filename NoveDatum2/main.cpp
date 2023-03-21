#include <iostream>
#include "datum.h"

int main() {
    int d, m, r, pocetdni = 0;
    char rozhodnuti;

    do {
        datum d1;
        std::cout << "Objekt d1 vytvoreny vychozim konstruktorem: " << d1 << " Pocet dni: od 1.1.1970 je  "
                  << d1.pocetDniOd1970() << ", den v tydnu je " << d1.denVTydnu() << std::endl;

        std::cout << "--------------------------------------------------------------" << std::endl;

        datum d2 (1,1,2000);
        std::cout << "Objekt d2 vytvoreny konstruktorem s parametry: " << d2 << " Pocet dni: od 1.1.1970 je  "
                  << d2.pocetDniOd1970() << ", den v tydnu je " << d2.denVTydnu() << std::endl;

        std::cout << "--------------------------------------------------------------" << std::endl;

        datum d3(d2);
        std::cout << "Objekt d3 vytvoreny kopirovacim konstruktorem: " << d3 << " Pocet dni: od 1.1.1970 je  "
                  << d3.pocetDniOd1970() << ", den v tydnu je " << d3.denVTydnu() << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;

        std::cout << "Zadani noveho data: \n" << std::endl;

        std::cout << "Zadej den: ";
        std::cin >> d;
        d1.setDen(d);

        std::cout << "Zadej mesic: ";
        std::cin >> m;
        d1.setMesic(m);

        std::cout << "Zadej rok: ";
        std::cin >> r;
        d1.setRok(r);

        std::cout << "--------------------------------------------------------------" << std::endl;
        std::cout << "Objekt d1 po zmene: " << d1 << " Pocet dni: od 1.1.1970 je  "
                  << d1.pocetDniOd1970() << ", den v tydnu je " << d1.denVTydnu() << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;

        std::cout << "Zadej pocet dni od 1.1.1970: " << std::endl;
        std::cin >> pocetdni;
        d3.vytvorDatumOd1970(pocetdni);

        std::cout << "Objekt d3 po prevedeni: " << d3 << " Pocet dni: od 1.1.1970 je  "
                  << d3.pocetDniOd1970() << ", den v tydnu je " << d3.denVTydnu() << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;

        std::cout << "Objekty d1 a d3 ";
        d1==d3 ? std::cout << "jsou" : std::cout << "nejsou";
        std::cout <<" shodne" << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;

        std::cout << "Kolik dnu chces k datu v objektu d3 pricist: ";
        std::cin >> d;
        d3.prictiDny(d);

        std::cout << "Objekt d3 po pricteni: " << d << " dnu: " << d3 << " Pocet dni: od 1.1.1970 je  "
                  << d3.pocetDniOd1970() << ", den v tydnu je " << d3.denVTydnu() << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;

        std::cout << "Pro pokracovani zadej 'k': ";
        std::cin >> rozhodnuti;
        rozhodnuti = tolower(rozhodnuti);
    } while (rozhodnuti == 'k');




    return 0;
}
