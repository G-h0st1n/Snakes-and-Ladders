// Player.cpp
#include "Player.h"

Player::Player(int number) : position(1), playerNumber(number) {}

void Player::move(int steps) {
    position = position + steps;
    if (position >= 30) {
        position = 30;
    };
}

int Player::getPosition() const {
    return position;
}

int Player::getPlayerNumber() const {
    return playerNumber;
}
