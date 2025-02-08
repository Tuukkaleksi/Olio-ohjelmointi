#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H

#include "seuraaja.h"

class Notifikaattori
{
public:
    Notifikaattori();
    ~Notifikaattori();

    void lisaa(Seuraaja* uusi);
    void poista(string nimi);
    void tulosta() const;

    void postita(string viesti) const;

private:
    Seuraaja *seuraajat = nullptr;
};

#endif // NOTIFIKAATTORI_H
