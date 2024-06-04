#ifndef GAMETYPE_H
#define GAMETYPE_H

class MyGame; // Forward declaration of MyGame

class GameType {
public:
    virtual void play(MyGame& game) = 0;
    virtual ~GameType() {}
};

class ManualGame : public GameType {
public:
    void play(MyGame& game) override;
};

class AutomaticGame : public GameType {
public:
    void play(MyGame& game) override;
};

#endif // GAMETYPE_H
