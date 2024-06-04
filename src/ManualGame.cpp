#include "GameType.h"
#include "MyGame.h"
#include <iostream>

void ManualGame::play(MyGame& game) {
    game.printInstructionMenu();
    bool gameOver = false;

    while (true) {
        char command;
        std::cin >> command;

        if (command == 'E') {
            std::cout << "Thanks for playing!!!\n";
            break;
        } else if (command == 'C') {
            game.executeTurn((game.getTurnNumber() - 1) % game.getPlayerCount());
            gameOver = game.checkGameOver((game.getTurnNumber() - 1) % game.getPlayerCount());
            if (gameOver) break;
            game.incrementTurnNumber();
            if (game.getTurnNumber() > game.getMaxTurns()) {
                std::cout << "No one won. Maximum number of turns reached.\n";
                break;
            }
        } else {
            std::cout << "Invalid option, please press C to continue next turn or E to end the game\n";
        }
    }

    std::cout << "-- GAME OVER --\n";
}
