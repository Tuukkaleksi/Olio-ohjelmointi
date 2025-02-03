#include "pankkitili.h"

Pankkitili::Pankkitili(string n)
{
    omistaja = n;
    cout << "Pankkitili luotu omistajalle: " << omistaja << endl;
}

double Pankkitili::getBalance() const
{
    // getteri saldolle
    return saldo;
}

bool Pankkitili::deposit(double sum)
{
    if (sum < 0) {
        return false;
    }
    saldo += sum;
    return true;
}

bool Pankkitili::withdraw(double sum)
{
    // Negatiivisia nostoja/talletuksia ei voi tehdä.
    if (sum < 0) {
        return false;
    // Saldo ei saa mennä negatiiviseksi, ei voi nostaa enempää mitä saldo on.
    } else if (sum > saldo) {
        return false;
    }
    saldo -= sum;
    return true;
}
