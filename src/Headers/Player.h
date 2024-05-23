// Player.h
#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int position;
    int playerNumber;
public:
    Player(int number);
    void move(int steps);
    int getPosition() const;
    int getPlayerNumber() const;
};

#endif // PLAYER_H