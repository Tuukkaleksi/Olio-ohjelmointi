#include "chef.h"

Chef::Chef() {}

Chef::Chef(string name)
{
    chefName = name;
    cout << "Chef konstruktori, kokin nimi " << chefName << endl;
}

Chef::~Chef()
{
    cout << "Chef desktruktori " << endl;
}

string Chef::getChefName() const
{
    return chefName;
}

int Chef::makeSalad(int aines)
{
    cout << "Salaatti aineksia " << aines << endl;
    // 1. Salaatti: yhteen annokseen tarvitaan 5 ainesta
    int annoksia = aines / 5;
    // 2. return palauttavat annosten määrä
    return annoksia;
}

int Chef::makeSoup(int aines)
{
    cout << "Keitto aineksia " << aines << endl;
    // 1. Keitto: yhteen tarvitaan 3 ainesta
    int annoksia = aines / 3;
    // return annosten määrä
    return annoksia;
}
