#include "game.h"

using namespace std;

int main()
{
    int maxnum;
    cout << "Anna suurin arvo, jota voidaan arvata: ";
    cin >> maxnum;
    Game game(maxnum);
    game.play();
    return 0;
}
