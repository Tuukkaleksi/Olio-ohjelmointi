#ifndef ASIAKAS_H
#define ASIAKAS_H

#include "pankkitili.h"
#include "luottotili.h"

class Asiakas
{
public:
    Asiakas(string n, double lr);
    ~Asiakas();
    void showSaldo();
    bool talletus(double summa);
    bool nosto(double summa);
    bool luotonMaksu(double maksu);
    bool luotonNosto(double nosto);

    string getNimi() const;

    bool tiliSiirto(double summa, Asiakas &saaja);

private:
    Pankkitili kayttotili;
    Luottotili luottotili;
    string nimi;
};

#endif // ASIAKAS_H
