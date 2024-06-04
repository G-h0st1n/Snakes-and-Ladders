#include "Dice.h"
#include <cstdlib>
#include <ctime>

Dice::Dice() {
    std::srand(std::time(0)); // Seed the random number generator
}

int Dice::roll() {
    return (std::rand() % 6) + 1; // Return a value between 1 and 6
}
