// Game.cpp
#include "Game.h"
#include <iostream>

Game::Game() : board(), player1(1), player2(2), dice(), turn(1), gameOver(false) {}

bool Game::isGameOver() const {
    return gameOver;
}

void Game::start() {
    std::cout << "Press C to continue next turn, or E to end the game:\n";
}

void Game::takeTurn() {
    if (!gameOver) {
        processPlayerTurn(player1, dice.roll());
        if (!gameOver) {
            processPlayerTurn(player2, dice.roll());
        }
        turn++;
    }
}

void Game::processPlayerTurn(Player& player, int dieResult) {
    std::cout << turn << " " << player.getPlayerNumber() << " " << player.getPosition() << " " << dieResult << " ";
    player.move(dieResult);
    char tileType = board.getTileType(player.getPosition());
    std::cout << tileType << " ";
    if (tileType == 'L') {
        player.move(3); // Move up the ladder
    } else if (tileType == 'S') {
        player.move(-3); // Move down the snake
    }
    std::cout << player.getPosition() << std::endl;

    // Check for game end condition
    if (player.getPosition() == 30) {
        gameOver = true;
        std::cout << "-- GAME OVER --\n";
        std::cout << "Player " << player.getPlayerNumber() << " is the winner!!!\n";
    }
}

void Game::endGame() {
    gameOver = true;
    std::cout << "-- GAME OVER --\n";
    std::cout << "Thanks for playing!!!\n";
}
