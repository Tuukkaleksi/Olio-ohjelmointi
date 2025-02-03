#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H

#include "pankkitili.h"

class Luottotili : public Pankkitili
{
public:
    Luottotili(string n, double lr);

    virtual bool deposit(double sum) override;
    virtual bool withdraw(double sum) override;

protected:
    double luottoRaja = 0;
};

#endif // LUOTTOTILI_H
