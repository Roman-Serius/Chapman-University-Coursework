#include "Mario.h"

Mario::Mario() : lives(3), coins(0), powerLevel(1) {} // Default constructor

Mario::Mario(int lives, int coins, int powerLevel) : lives(lives), coins(coins), powerLevel(powerLevel) {}

Mario::~Mario() {}

int Mario::getLives() const { return lives; }
int Mario::getCoins() const { return coins; }
int Mario::getPowerLevel() const { return powerLevel; }

void Mario::setLives(int newLives) { lives = newLives; }
void Mario::setCoins(int newCoins) { coins = newCoins; }
void Mario::setPowerLevel(int newPowerLevel) { powerLevel = newPowerLevel; }