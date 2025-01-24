#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H

#include "chef.h"

class italianChef : public Chef
{
public:
    italianChef(string chefName);
    ~italianChef();

    bool askSecret(string passwordYr, int flourMaara, int waterMaara);

private:
    string password;
    int flour = 0;
    int water = 0;
    int makePizza();
};

#endif // ITALIANCHEF_H
