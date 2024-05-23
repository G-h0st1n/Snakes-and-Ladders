// Game.cpp
#include "Game.h"
#include <iostream>

Game::Game() : board(), player1(1), player2(2), dice(), turn(0), isGameOver(false) {}

void Game::start() {
    // Print instruction menu
    std::cout << "Press C to continue next turn, or E to end the game:\n";
}

void Game::takeTurn() {
    // Implementation of turn execution
}

void Game::endGame() {
    std::cout << "-- GAME OVER --\n";
}