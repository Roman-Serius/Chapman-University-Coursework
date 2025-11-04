// Soren Marius
// 002456139
// Marius@chapman.edu
// CPSC-350-01
// PA2:

#include <iostream>

using namespace std;

#ifndef MARIO_H
#define MARIO_H
class Mario {
public:
    Mario();
    Mario(int lives, int coins, int powerLevel);
    ~Mario();

    int getLives() const;
    int getCoins() const;
    int getPowerLevel() const;
    void setLives(int newLives);
    void setCoins(int newCoins);
    void setPowerLevel(int newPowerLevel);

private:
    int lives;
    int coins;
    int powerLevel;
};

#endif