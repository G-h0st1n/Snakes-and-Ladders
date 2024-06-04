#include "MyGame.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

MyGame::MyGame(int tiles, int snakes, int ladders, int penalty, int reward, int players, int turns) 
    : turnNumber(1), maxTurns(turns), playerCount(players) {
    playerPositions.resize(players, 0);

    // Initialize the board with normal tiles
    for (int i = 0; i < tiles; ++i) {
        board.push_back(new NormalTile());
    }

    // Place snakes on the board
    std::srand(std::time(0));
    for (int i = 0; i < snakes; ++i) {
        int pos = std::rand() % (tiles - 1) + 1; // Ensure it's not the first tile
        delete board[pos];
        board[pos] = new SnakeTile(penalty);
    }

    // Place ladders on the board
    for (int i = 0; i < ladders; ++i) {
        int pos = std::rand() % (tiles - 1) + 1; // Ensure it's not the first tile
        delete board[pos];
        board[pos] = new LadderTile(reward);
    }
}

MyGame::~MyGame() {
    for (auto tile : board) {
        delete tile;
    }
}

void MyGame::start(GameType* gameType) {
    gameType->play(*this);
}

void MyGame::printInstructionMenu() {
    std::cout << "Press C to continue next turn, or E to end the game:\n";
}

void MyGame::executeTurn(int player) {
    int currentPos = playerPositions[player];
    int diceRoll = dice.roll();
    int newPos = currentPos + diceRoll;

    if (newPos >= board.size()) {
        playerPositions[player] = board.size() - 1;
        std::cout << turnNumber << " " << (player + 1) << " " << (currentPos + 1) << " " << diceRoll << " N " << board.size() << "\n";
        std::cout << "Player " << (player + 1) << " is the winner!!!\n";
        return;
    }

    char newPosType = board[newPos]->getType();
    int finalPos = board[newPos]->getNextPosition(newPos);
    if (finalPos < 0) finalPos = 0;

    playerPositions[player] = finalPos;
    std::cout << turnNumber << " " << (player + 1) << " " << (currentPos + 1) << " " << diceRoll << " " << newPosType << " " << (finalPos + 1) << "\n";
}

bool MyGame::checkGameOver(int player) {
    if (playerPositions[player] >= board.size() - 1) {
        std::cout << "Player " << (player + 1) << " is the winner!!!\n";
        return true;
    }
    return false;
}
