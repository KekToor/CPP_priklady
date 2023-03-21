
#ifndef NOVEDATUM2_DATUM_H
#define NOVEDATUM2_DATUM_H
#include <iostream>


class datum {
public:
    datum();
    datum(const datum& orig);
    datum(int, int, int);

    virtual ~datum();

    [[nodiscard]] int getDen() const;
    [[nodiscard]] int getMesic() const;
    [[nodiscard]] int getRok() const;

    void setDen(int);
    void setMesic(int);
    void setRok(int);

    bool setDatum(int, int, int);

    int pocetDniOd1970() const;
    int denVTydnu() const;
    void vytvorDatumOd1970(int);
    void prictiDny(int d);


    bool operator==(const datum &rhs) const;
    datum & operator = (const datum &);

    friend std::ostream &operator<<(std::ostream &os, const datum &datum);


private:
    int den;
    int mesic;
    int rok;
    bool kontrolaData(int, int, int)const;
    void systemoveDatum();

};


#endif //NOVEDATUM2_DATUM_H
