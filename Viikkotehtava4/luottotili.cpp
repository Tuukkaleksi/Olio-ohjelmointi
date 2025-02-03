#include "luottotili.h"

Luottotili::Luottotili(string n, double lr)
    : Pankkitili(n)
{
    luottoRaja = lr;
    cout << "Luottoraja: " << luottoRaja << endl;
}

bool Luottotili::deposit(double sum)
{
    if (sum < 0) {
        return false;
    }
    saldo -= sum;
    if (saldo < 0) {
        saldo = 0;
    }
    return true;
}

bool Luottotili::withdraw(double sum)
{
    if (sum < 0) {
        return false;
    }
    // Luottotilin saldo saa mennä negatiiviseksi, mutta ei alle luottorajan
    int saldoSum = saldo + sum;
    if (saldoSum > luottoRaja) {
        return false;
    }
    // Lisätään saldoon summa, return true;
    saldo += sum;
    return true;
}
