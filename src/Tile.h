#ifndef TILE_H
#define TILE_H

class Tile {
public:
    virtual char getType() const = 0;
    virtual int getNextPosition(int currentPosition) const = 0;
    virtual ~Tile() {}
};

class NormalTile : public Tile {
public:
    char getType() const override { return 'N'; }
    int getNextPosition(int currentPosition) const override { return currentPosition; }
};

class SnakeTile : public Tile {
private:
    int penalty;
public:
    SnakeTile(int penalty) : penalty(penalty) {}
    char getType() const override { return 'S'; }
    int getNextPosition(int currentPosition) const override { return currentPosition - penalty; }
};

class LadderTile : public Tile {
private:
    int reward;
public:
    LadderTile(int reward) : reward(reward) {}
    char getType() const override { return 'L'; }
    int getNextPosition(int currentPosition) const override { return currentPosition + reward; }
};

#endif // TILE_H
