#ifndef GAME_H
#define GAME_H
#include <iostream>

using namespace std;

class Game
{
public:
    Game(int maxNumber);
    void play();
    void printGameResult();
    ~Game();

private:
    int maxNumber;
    int minNumber;
    int lastArvaus;
    int randNumber;
    int arvaukset;
};

#endif // GAME_H
