#ifndef MYGAME_H
#define MYGAME_H

#include "Dice.h"

class MyGame {
private:
    int playerPositions[2];
    int turnNumber;
    Dice dice;
    char board[30];

public:
    MyGame();
    void start();
    void printInstructionMenu();
    void executeTurn(int player);
    bool checkGameOver(int player);
};

#endif // MYGAME_H
