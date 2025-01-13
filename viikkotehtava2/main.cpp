#include "game.h"

using namespace std;

int main()
{
    int maxNumber;
    cout << "Anna suurin arvo, jota voidaan arvata: ";
    cin >> maxNumber;
    Game game(maxNumber);
    game.play();
    return 0;
}
