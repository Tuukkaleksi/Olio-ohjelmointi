#include <iostream>
#include "notifikaattori.h"

using namespace std;

int main()
{
    Notifikaattori n;

    /* Norton antaa virhe ilmoituksen että on vaarallinen .exe sovellus :D */
    /* Vaikka tehnyt viikkotehtava5.ppx dia 7 mukaisesti. */
    Seuraaja s1("Anna");
    Seuraaja s2("Matti");
    Seuraaja s3("Emma");

    n.lisaa(&s1);
    n.lisaa(&s2);
    n.lisaa(&s3);

    cout << "Seuraajat: " << endl;
    n.tulosta();

    cout << "Lahetetaan viesti: " << endl;
    n.postita("Hei kaikki!");

    cout << "Poistetaan Matti... " << endl;
    n.poista("Matti");

    cout << "Seuraajat poistamisen jalkeen: " << endl;
    n.tulosta();

    return 0;
}
