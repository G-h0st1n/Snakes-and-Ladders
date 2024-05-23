// Board.cpp
#include "Board.h"

Board::Board() : tiles(30, 'N') {
    // Initialize snakes and ladders
    tiles[5] = 'S'; // Example positions for snakes
    tiles[14] = 'S';
    tiles[23] = 'S';
    tiles[3] = 'L'; // Example positions for ladders
    tiles[10] = 'L';
    tiles[20] = 'L';
}

char Board::getTileType(int position) const {
    return tiles[position - 1];
}

void Board::setTileType(int position, char type) {
    tiles[position - 1] = type;
}