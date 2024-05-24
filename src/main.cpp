// main.cpp
#include "Game.h"
#include <iostream>
#include <ctime>

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    Game game;
    game.start();

    char input;
    while (!game.isGameOver()) {
        if (std::cin >> input) {
            if (input == 'C' || input == 'c') {
                game.takeTurn();
            } else if (input == 'E' || input == 'e') {
                game.endGame();
                break;
            } else {
                std::cout << "Invalid option, please press C to continue next turn or E to end the game\n";
            }
        } else {
            // Handle end of input stream (e.g., EOF or input error)
            game.endGame();
            break;
        }
    }

    return 0;
}
