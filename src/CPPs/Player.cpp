// Player.cpp
#include "Headers/Player.h"

Player::Player(int number) : position(1), playerNumber(number) {}

void Player::move(int steps) {
    position += steps;
}

int Player::getPosition() const {
    return position;
}

int Player::getPlayerNumber() const {
    return playerNumber;
}
