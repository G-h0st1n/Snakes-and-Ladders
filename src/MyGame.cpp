#include "MyGame.h"
#include <iostream>

MyGame::MyGame() {
    playerPositions[0] = 0;
    playerPositions[1] = 0;
    turnNumber = 1;
    
    // Initialize the board
    for (int i = 0; i < 30; ++i) {
        board[i] = 'N';
    }
    
    // Place snakes and ladders
    board[5] = 'S'; board[10] = 'S'; board[15] = 'S';
    board[3] = 'L'; board[12] = 'L'; board[21] = 'L';
}

void MyGame::start() {
    printInstructionMenu();
    
    while (true) {
        char command;
        std::cin >> command;

        if (command == 'e') {
            std::cout << "Thanks for playing!!!\n";
            break;
        } else if (command == 'c') {
            executeTurn((turnNumber - 1) % 2);
            if (checkGameOver((turnNumber - 1) % 2)) break;
            ++turnNumber;
        } else {
            std::cout << "Invalid option, please press C to continue next turn or E to end the game\n";
        }
    }

    std::cout << "-- GAME OVER --\n";
}

void MyGame::printInstructionMenu() {
    std::cout << "Press C to continue next turn, or E to end the game:\n";
}

void MyGame::executeTurn(int player) {
    int currentPos = playerPositions[player];
    int diceRoll = dice.roll();
    int newPos = currentPos + diceRoll;

    if (newPos >= 30) {
        playerPositions[player] = 29;
        std::cout << turnNumber << " " << (player + 1) << " " << (currentPos + 1) << " " << diceRoll << " N " << 30 << "\n";
        std::cout << "Player " << (player + 1) << " is the winner!!!\n";
        return;
    }

    char newPosType = board[newPos];
    int finalPos = newPos;
    
    if (newPosType == 'S') {
        finalPos = newPos - 3;
    } else if (newPosType == 'L') {
        finalPos = newPos + 3;
    }

    playerPositions[player] = finalPos;
    std::cout << turnNumber << " " << (player + 1) << " " << (currentPos + 1) << " " << diceRoll << " " << newPosType << " " << (finalPos + 1) << "\n";
}

bool MyGame::checkGameOver(int player) {
    if (playerPositions[player] >= 29) {
        std::cout << "Player " << (player + 1) << " is the winner!!!\n";
        return true;
    }
    return false;
}
