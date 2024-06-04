#ifndef MYGAME_H
#define MYGAME_H

#include "Dice.h"
#include "Tile.h"
#include "GameType.h"
#include <vector>

class MyGame {
private:
    std::vector<int> playerPositions;
    int turnNumber;
    Dice dice;
    std::vector<Tile*> board;
    int maxTurns;
    int playerCount;

public:
    MyGame(int tiles, int snakes, int ladders, int penalty, int reward, int players, int turns);
    ~MyGame();
    void start(GameType* gameType);
    void printInstructionMenu();
    void executeTurn(int player);
    bool checkGameOver(int player);
    int getTurnNumber() const { return turnNumber; }
    void incrementTurnNumber() { ++turnNumber; }
    int getPlayerCount() const { return playerCount; }
    int getMaxTurns() const { return maxTurns; }
};

#endif // MYGAME_H
