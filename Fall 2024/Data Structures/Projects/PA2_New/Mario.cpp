//Soren Marius
//002456139
//Marius@chapman.edu
//CPSC-350-01
//PA2:

#include "Mario.h"
#include <iostream>

Mario::Mario(){
    lives = 0;
    coins = 0;
    PowerLevel = 0;
}

Mario:: Mario(int lives, int coins,int PowerLevel){
    
    this->lives = lives;
    this->coins = coins;
    this->PowerLevel = PowerLevel;
}

Mario:: ~Mario(){}

int Mario::getLives() const 
{
 return lives;
}

int Mario::getCoins() const 
{
 return coins;
}

int Mario::getPowerLevel() const 
{
 return PowerLevel;
}

void Mario::setLives(int lives) 
{
    this->lives = lives;
}

void Mario::setCoins(int coins) 
{
    this->coins = coins;
}

void Mario::setPowerLevel(int PowerLevel) 
{
    this->PowerLevel = PowerLevel;
}

void Mario::coinCollect() 
{
 coins++;
 if(coins == 20)
 {
    lives++;
    coins = 0;
 }
}

void Mario::loseLife()
{
    if(lives > 0)
    {
        lives--;
        setPowerLevel(0);
    }
}

void Mario::powerIncrease() 
{
 if(PowerLevel < 2)
 {
    PowerLevel++;
 }
}

void Mario::powerDecrease() 
{
    if(PowerLevel > 0)
    {
        PowerLevel--;
    }
    else if (PowerLevel == 0 && lives > 0)
    {
        loseLife();
    }
}