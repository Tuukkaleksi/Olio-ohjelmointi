#include "italianchef.h"

italianChef::italianChef(string chefName) : Chef(chefName), password("pizza")
{
    cout << "ItalianChef konstruktori, kokin nimi " << getChefName() << endl;
}

italianChef::~italianChef()
{
    cout << "ItalianChef desktruktori" << endl;
}

bool italianChef::askSecret(string passwordYr, int flourMaara, int waterMaara)
{
    if(passwordYr == password) {
        cout << "Password ok!" << endl;
        flour = flourMaara;
        water = waterMaara;
        int pizzas = makePizza();
        cout << "Valmistettiin " << pizzas << " pizzaa" << endl;
        return true;
    }
    else
    {
        cout << "Password not ok!" << endl;
        return false;
    }
}

int italianChef::makePizza()
{
    cout << "Pizza-ainekset: jauhoja " << flour << ", vetta " << water << endl;
    int maxFlour = flour / 5;
    int maxWater = water / 5;
    int pizzas = min(maxFlour, maxWater);

    flour -= pizzas * 5;
    water -= pizzas * 5;

    return pizzas;
}
