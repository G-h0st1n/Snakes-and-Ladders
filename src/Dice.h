#ifndef DICE_H
#define DICE_H

#include <cstdlib>

class Dice {
private:
    int sides;

public:
    Dice() : sides(6) {} // Initialize with 6 sides for a standard die

    int roll() {
        return rand() % sides + 1; // Return a random number between 1 and 6
    }
};

#endif // DICE_H
