#include "notifikaattori.h"
#include <iostream>

using namespace std;

Notifikaattori::Notifikaattori()
{
    cout << "Notifikaattori luotu." << endl;
}

Notifikaattori::~Notifikaattori()
{
    while(seuraajat) {
        Seuraaja* poistettava = seuraajat;
        seuraajat = seuraajat->next;
        delete poistettava;
    };
    cout << "Notifikaattori tuhottu." << endl;
}

void Notifikaattori::lisaa(Seuraaja *uusi)
{
    uusi->next = seuraajat;
    seuraajat = uusi;
    cout << uusi->getNimi() << " lisatty seuraajaksi." << endl;
}

void Notifikaattori::poista(string nimi)
{
    Seuraaja* nykyinen = seuraajat;
    Seuraaja* edellinen = nullptr;

    while (nykyinen) {
        if (nykyinen->getNimi() == nimi) {
            if (edellinen) {
                edellinen->next = nykyinen->next;
            } else {
            seuraajat = nykyinen->next;
            }
            delete nykyinen;
            cout << "Seuraaja " << nimi << " poistettu." << endl;
            return;
        }
        edellinen = nykyinen;
        nykyinen = nykyinen->next;
    }
    cout << "Seuraaja " << nimi << " ei loytynyt." << endl;
}

void Notifikaattori::tulosta() const
{
    Seuraaja* nykyinen = seuraajat;
    while (nykyinen) {
        cout << nykyinen->getNimi() << endl;
        nykyinen = nykyinen->next;
    };
}

void Notifikaattori::postita(string viesti) const
{
    Seuraaja* nykyinen = seuraajat;
    while (nykyinen) {
        nykyinen->paivitys(viesti);
        nykyinen = nykyinen->next;
    };
}
