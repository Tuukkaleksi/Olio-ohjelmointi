#include "game.h"

Game::Game(int maxnum) : maxnum(maxnum), arvaukset(0) {
    srand(time(NULL));
    satluku = rand() % maxnum + 1;
    cout << "GAME CONSTRUCTION: object initialized with " << maxnum << " as a max value" << endl;
}

Game::~Game() {
    cout << "GAME DESTRUCTION: object cleared from stack memory" << endl;
}

void Game::play() {
    do {
        cout << "Arvaa luku (1-" << maxnum << "): ";
        cin >> arvaus;
        yritykset++;
        if (arvaus < satluku) {
            cout << "Liian pieni!" << endl;
        } else if (arvaus > satluku) {
            cout << "Liian suuri!" << endl;
        }
    } while (arvaus != satluku);
    printGameResult();
}

void Game::printGameResult() {
    cout << "Oikea vastaus oli " << satluku << "." << endl;
    cout << "Arvaukset: " << yritykset << "." << endl;
}
