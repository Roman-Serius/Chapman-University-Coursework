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
     int gridSize;
     Level* levels;
     int L;


public:
     FileProcessor* fileProcessor;
     int numLevels;
     

     void randomItemPlace(Level &level, char item, int count);
};

#endif
