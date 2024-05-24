// Board.h
#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
private:
    std::vector<char> tiles;
public:
    Board();
    char getTileType(int position) const;
    void setTileType(int position, char type);
};

#endif // BOARD_H