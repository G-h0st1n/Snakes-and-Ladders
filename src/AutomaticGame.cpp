#include "GameType.h"
#include "MyGame.h"
#include <iostream>

void AutomaticGame::play(MyGame& game) {
    bool gameOver = false;
    while (game.getTurnNumber() <= game.getMaxTurns() && !gameOver) {
        game.executeTurn((game.getTurnNumber() - 1) % game.getPlayerCount());
        gameOver = game.checkGameOver((game.getTurnNumber() - 1) % game.getPlayerCount());
        game.incrementTurnNumber();
    }

    if (!gameOver) {
        std::cout << "No one won. Maximum number of turns reached.\n";
    }

    std::cout << "-- GAME OVER --\n";
}
