#include "asiakas.h"

Asiakas::Asiakas(string n, double lr)
    : kayttotili(n), luottotili(n, lr)
{
    nimi = n;
    cout << "Nimi: " << nimi << endl;
}

Asiakas::~Asiakas()
{
    cout << "Pankkitili (" << nimi << ") tuhottu" << endl;
}

void Asiakas::showSaldo()
{
    cout << "Asiakas: " << nimi << endl;
    cout << "Kayttotilin saldo: " << kayttotili.getBalance() << " euroa" << endl;
    cout << "Luottotilin saldo: " << luottotili.getBalance() << " euroa" << endl;
    return;
}

bool Asiakas::talletus(double summa)
{
    cout << "Asiakas " << nimi << " tallettaa" << endl;
    bool onnistuiko = kayttotili.deposit(summa);
    if (onnistuiko == false) {
        cout << "Meni pieleen" << endl;
    }
    return onnistuiko;
}

bool Asiakas::nosto(double summa)
{
    cout << "Asiakas " << nimi << " nostaa" << endl;
    bool onnistuiko = kayttotili.withdraw(summa);
    if (onnistuiko == false) {
        cout << "Meni pieleen" << endl;
    }
    return onnistuiko;
}

bool Asiakas::luotonMaksu(double maksu)
{
    cout << "Asiakas " << nimi << " maksaa luottoa" << endl;
    bool onnistuiko = luottotili.deposit(maksu);
    if (onnistuiko == false) {
        cout << "Meni pieleen" << endl;
    }
    return onnistuiko;
}

bool Asiakas::luotonNosto(double nosto)
{
    cout << "Asiakas " << nimi << " nostaa luottoa" << endl;
    bool onnistuiko = luottotili.withdraw(nosto);
    if (onnistuiko == false) {
        cout << "Meni pieleen" << endl;
    }
    return onnistuiko;
}

string Asiakas::getNimi() const
{
    return nimi;
}

bool Asiakas::tiliSiirto(double summa, Asiakas &saaja)
{
    if (summa <= 0) {
        cout << "Siirto epaonnistui" << endl;
        return false;
    }
    cout << "Asiakas " << nimi << " siirtaa " << summa << " asiakkaalle " << saaja.getNimi() << endl;

    if (kayttotili.withdraw(summa)) {
        if (saaja.talletus(summa)) {
            cout << "Tilisiirto onnistui" << endl;
            return true;
        } else {
            // palauttaa rahat
            cout << "Talletus epaonnistui" << endl;
            kayttotili.deposit(summa);
        }
    } else {
        cout << "Tilisiirto epaonnistui: Ei tarpeeksi rahaa." << endl;
    }

    return false;
}
