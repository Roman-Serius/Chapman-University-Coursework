// Soren Marius
// 002456139
// Marius@chapman.edu
// CPSC-350-01
// PA2: Not so Super Mario Bros.
#ifndef WORLD_H
#define WORLD_H

#include "Level.h"
#include "FileProcessor.h"
class Level;
class FileProcessor;
class World
{
    public:

     World(int numLevels, int gridSize);

     ~World();

    void populateWorld( int perCoins, int perNothing, int perGoomba, int perKoopa, int perMushroom);
     void populateLevel(int currentLevelNum, int perCoins, int perNothing, int perGoomba, int perKoopa, int perMushroom);
     void displayWorld(FileProcessor& fileProcessor);


     
     FileProcessor* fileProcessor;
     int numLevels;
     int gridSize;
     Level* levels;

     void randomItemPlace(Level &level, char item, int count);
};

#endif
