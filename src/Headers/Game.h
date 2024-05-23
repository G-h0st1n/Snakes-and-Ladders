// Game.h
#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include "Dice.h"

class Game {
private:
    Board board;
    Player player1;
    Player player2;
    Dice dice;
    int turn;
    bool isGameOver;
public:
    Game();
    void start();
    void takeTurn();
    void endGame();
};

#endif // GAME_H