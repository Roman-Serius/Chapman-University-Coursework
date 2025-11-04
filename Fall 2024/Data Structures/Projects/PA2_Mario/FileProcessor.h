// Soren Marius
// 002456139
// Marius@chapman.edu
// CPSC-350-01
// PA2:

#include "Mario.h"
#include "World.h"
#include <iostream>
#include <fstream>

using namespace std;

class FileProcessor {
public:
    FileProcessor();
    ~FileProcessor();
    void processFile(string input);
    void outputFile(Mario &mario);
    int getNumLevels();
    int getGridSize();
    int getInitLives();
    int getPerCoins();
    int getPerNothing();
    int getPerGoomba();
    int getPerKoopa();
    int getPerMushroom();

private:
    string numLevels;
    string gridSize;
    string initLives;
    string perCoins;
    string perNothing;
    string perGoomba;
    string perKoopa;
    string perMushroom;
    
    int numLevelsInt;
    int gridSizeInt;
    int initLivesInt;
    int perCoinsInt;
    int perNothingInt;
    int perGoombaInt;
    int perKoopaInt;
    int perMushroomInt;

    string bolden(string regText);
    string italicize(string regText);
    ifstream myfile;
};