#ifndef GAME_H
#define GAME_H
#include <iostream>

using namespace std;

class Game
{
public:
    Game(int maxnum);
    void play();
    void printGameResult();
    ~Game();

private:
    int maxnum;
    int minnum;
    int arvaus;
    int satluku;
    int yritykset;
};

#endif // GAME_H
