#ifndef WORLD_H
#define WORLD_H

#include "Level.h"

class World {
public:
    World(int numLevels, int gridSize);
    ~World();

    void populateLevel(int currentLevelNum, int perCoins, int perNothing, int perGoomba, int perKoopa, int perMushroom);
    void displayWorld() const;
    
   

private:
    int numLevels;
    int gridSize;
    Level* levels;

    void randomItemPlace(Level &level, char item, int count);
};


#endif