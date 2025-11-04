#include "Mario.h"

Mario::Mario(int lives, int powerLevel) : lives(lives), powerLevel(powerLevel), coins(0) {}

void Mario::collectCoin() {
    coins++;
    if (coins % 20 == 0) {
        lives++;
        coins = 0;  // reset coins after gaining life
    }
}

void Mario::eatMushroom() {
    if (powerLevel < 2) {
        powerLevel++;
    }
}

void Mario::loseLife() {
    lives--;
}

void Mario::powerUp() {
    if (powerLevel < 2) {
        powerLevel++;
    }
}

void Mario::powerDown() {
    if (powerLevel > 0) {
        powerLevel--;
    } else {
        loseLife();
    }
}

int Mario::getLives() const {
    return lives;
}

int Mario::getCoins() const {
    return coins;
}

int Mario::getPowerLevel() const {
    return powerLevel;
}
