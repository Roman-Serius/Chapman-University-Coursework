#ifndef MARIO_H
#define MARIO_H

class Mario {
public:
    Mario(int lives, int powerLevel);

    // Functions to handle Mario's interactions
    void collectCoin();
    void eatMushroom();
    void loseLife();
    void powerUp();
    void powerDown();

    // Getters for current state
    int getLives() const;
    int getCoins() const;
    int getPowerLevel() const;

private:
    int lives;
    int powerLevel;
    int coins;
};

#endif
