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
    bool gameOver;

public:
    Game();
    bool isGameOver() const;
    void start();
    void takeTurn();
    void endGame();
    void processPlayerTurn(Player& player, int dieResult);
};

#endif // GAME_H
