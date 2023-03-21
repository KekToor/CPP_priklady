#include "datum.h"
#include <ctime>

datum::datum() {
    systemoveDatum();
}

datum::datum(const datum &orig) {
    this->den = orig.den;
    this->mesic = orig.mesic;
    this->rok = orig.rok;
}

datum::datum(int d, int m, int r) {
    if(!setDatum(d, m, r)) {
        std::cout << "Neplatne datum, bude nastaveno systemove datum." << std::endl;
        systemoveDatum();
    }
}

datum::~datum() {

}

int datum::getDen() const {
    return den;
}

int datum::getMesic() const {
    return mesic;
}

int datum::getRok() const {
    return rok;
}

void datum::setDen(int d) {
    if(kontrolaData(d, this->mesic, this->rok)) {
        this->den = d;
    }
}

void datum::setMesic(int m) {
    if(kontrolaData(this->den, m, this->rok)) {
        this->mesic = m;
    }
}

void datum::setRok(int r) {
    if(kontrolaData(this->den, this->mesic, r)) {
        this->rok = r;
    }
}

bool prestupnyRok(int r) {
    if (r % 4 == 0 && (r % 100 != 0 || r % 400 == 0)) {
        return true;
    }
    return false;
}

int dnyVMesici(int m, int r) {
    int dny[] = {31, prestupnyRok(r) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return dny[m-1];
}

bool datum::kontrolaData(int d, int m, int r) const {
    if (r > 1969 && r < 2051 && m > 0 && m < 13) {
        if(dnyVMesici(m, r) == 30) {
            if(d > 0 && d < 31) {
                return true;
            }
            return false;
        } else if (dnyVMesici(m, r) == 31) {
            if(d > 0 && d <32) {
                return true;
            }
            return false;
        } else if (dnyVMesici(m, r) == 29) {
            if (d > 0 && d < 30) {
                return true;
            }
            return false;
        } else if (dnyVMesici(m, r) == 28) {
            if (d > 0 && d < 29) {
                return true;
            }
            return false;
        }
    }
    return false;
}

bool datum::setDatum(int d, int m, int r) {
    if(kontrolaData(d, m, r)) {
        this->den = d;
        this->mesic = m;
        this->rok = r;
        return true;
    }
    return false;
}

void datum::systemoveDatum() {
    time_t t;
    struct tm * tt;
    time (&t);
    tt = localtime(&t);
    this->den = tt->tm_mday;
    this->mesic = tt->tm_mon + 1;
    this->rok = tt->tm_year + 1900;
}

std::ostream &operator<<(std::ostream &os, const datum &datum) {
    os << datum.den << "." << datum.mesic << "." << datum.rok;
    return os;
}

int datum::pocetDniOd1970() const {
    int d = getDen();
    int m = getMesic();
    int r = getRok();
    int celkem = 0;
    for (int i = r - 1; i > 1969; i--) {
        if (prestupnyRok(i)) {
            celkem += 366;
        } else {
            celkem += 365;
        }
    }

    for (int j = m-1; j > 0; j--) {
        celkem += dnyVMesici(j, r);
    }

    return celkem + d - 1;
}

int datum::denVTydnu() const {
    int dny = pocetDniOd1970() + 4;
    if (dny % 7 == 0) {
        return 7;
    } else {
        return dny % 7;
    }
}

bool datum::operator==(const datum &rhs) const {
    return den == rhs.den &&
           mesic == rhs.mesic &&
           rok == rhs.rok;
}

datum &datum::operator=(const datum &rhs) {
    if(this != &rhs) {
        this->den = rhs.getDen();
        this->mesic = rhs.getMesic();
        this->rok = rhs.getRok();
    }
    return *this;
}

void datum::vytvorDatumOd1970(int d) {
    int m = 1;
    int r = 1970;

    while(d >= 365) {
        if(prestupnyRok(r)) {
            d -= 366;
        } else {
            d -= 365;
        }
        r++;
    }

    for(; d >= dnyVMesici(m, r); m++) {
        d -= dnyVMesici(m, r);
    }
    std::cout << d+1 << "." << m << "." << r << std::endl;

    setDatum(d+1, m, r);
}

void datum::prictiDny(int d) {
    vytvorDatumOd1970(pocetDniOd1970() + d);
}


