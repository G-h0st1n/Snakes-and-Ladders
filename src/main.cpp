// main.cpp
#include "Headers/Game.h"
#include <iostream>

int main() {
    Game game;
    game.start();

    char input;
    while (std::cin >> input) {
        if (input == 'C' || input == 'c') {
            game.takeTurn();
        } else if (input == 'E' || input == 'e') {
            game.endGame();
            break;
        } else {
            std::cout << "Invalid option, please press C to continue next turn or E to end the game\n";
        }
    }

    return 0;
}
