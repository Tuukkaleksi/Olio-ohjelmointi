#include "game.h"

Game::Game(int maxNumber) : maxNumber(maxNumber), arvaukset(0) {
    srand(time(NULL));
    randNumber = rand() % maxNumber + 1;
    cout << "GAME CONSTRUCTION: object initialized with " << maxNumber << " as a max value" << endl;
}

Game::~Game() {
    cout << "GAME DESTRUCTION: object cleared from stack memory" << endl;
}

void Game::play() {
    do {
        cout << "Arvaa luku (1-" << maxNumber << "): ";
        cin >> lastArvaus;
        arvaukset++;
        if (lastArvaus < randNumber) {
            cout << "Liian pieni!" << endl;
        } else if (lastArvaus > randNumber) {
            cout << "Liian suuri!" << endl;
        }
    } while (lastArvaus != randNumber);
    printGameResult();
}

void Game::printGameResult() {
    cout << "Oikea vastaus oli " << randNumber << "." << endl;
    cout << "Arvaukset: " << arvaukset << "." << endl;
}
