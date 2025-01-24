#include <iostream>
#include "chef.h"
#include "italianchef.h"

using namespace std;

int main()
{
    Chef c_olio("Gordon");

    int annoksia = c_olio.makeSalad(10);
    cout << "Salaattiannoksia tehtiin " << annoksia << endl;

    int keittoannoksia = c_olio.makeSoup(12);
    cout << "Keittoannoksia tehtiin " << keittoannoksia << endl;

    cout << "" << endl;
    cout << "" << endl;

    italianChef i_olio("Mario");
    i_olio.askSecret("pizza", 15, 20);

    return 0;
}
