#include "asiakas.h"

int main()
{
    Asiakas asiakas1("Tuukka", 1000); // Luodaan ensimmainen asiakas
    Asiakas asiakas2("Matti", 500);  // Luodaan toinen asiakas

    cout << "Alkuperaiset saldot:" << endl;;
    asiakas1.showSaldo();
    asiakas2.showSaldo();

    cout << "Talletetaan 500 euroa Tuukan kayttotilille:" << endl;
    asiakas1.talletus(500);

    cout << "Suoritetaan tilisiirto 200 Tuukalta Matille:" << endl;;
    asiakas1.tiliSiirto(200, asiakas2);

    cout << "Saldot siirron jalkeen:" << endl;;
    asiakas1.showSaldo();
    asiakas2.showSaldo();

    cout << "Yritetaan tilisiirto, jossa ei tarpeeksi rahaa:" << endl;;
    asiakas1.tiliSiirto(1000, asiakas2);

    cout << "Saldot epaonnistuneen siirron jalkeen:" << endl;;
    asiakas1.showSaldo();
    asiakas2.showSaldo();
    return 0;
}
