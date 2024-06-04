#include "MyGame.h"
#include "GameType.h"
#include <iostream>

int main() {
    int tiles, snakes, ladders, penalty, reward, players, turns;
    char gameTypeChar;

    std::cout << "How many tiles? ";
    std::cin >> tiles;
    std::cout << "How many snakes? ";
    std::cin >> snakes;
    std::cout << "How many ladders? ";
    std::cin >> ladders;
    std::cout << "Penalty for snakes? ";
    std::cin >> penalty;
    std::cout << "Reward for ladders? ";
    std::cin >> reward;
    std::cout << "Number of players? ";
    std::cin >> players;
    std::cout << "Maximum number of turns? ";
    std::cin >> turns;
    std::cout << "Game Type (A for automatic, M for manual): ";
    std::cin >> gameTypeChar;

    GameType* gameType;
    if (gameTypeChar == 'A') {
        gameType = new AutomaticGame();
    } else {
        gameType = new ManualGame();
    }

    MyGame game(tiles, snakes, ladders, penalty, reward, players, turns);
    game.start(gameType);

    delete gameType;

    return 0;
}
