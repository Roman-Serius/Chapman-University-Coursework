//Soren Marius
//002456139
//Marius@chapman.edu
//CPSC-350-01
//PA2:

#include <iostream>

using namespace std;

class Mario{
    public:
        Mario();
        Mario(int lives, int coins,int PowerLevel);
        ~Mario();
        
        int getLives() const;
        int getCoins() const;
        int getPowerLevel() const;

        void setLives(int lives);
        void setCoins(int coins);
        void setPowerLevel(int PowerLevel);

        void coinCollect();
        void loseLife();
        void powerDecrease();
        void powerIncrease();


    private:
        int lives;
        int coins;
        int PowerLevel;

};

