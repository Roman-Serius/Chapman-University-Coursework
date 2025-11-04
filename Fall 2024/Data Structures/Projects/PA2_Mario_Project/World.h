#ifndef WORLD_H
#define WORLD_H

#include "Level.h"

class World {
public:
    World(int levels, int gridSize);
    ~World();

    void populateLevel(int level, int coinPercentage, int goombaPercentage, int koopaPercentage, int mushroomPercentage);
    void displayWorld() const;

private:
    int numLevels;
    Level** levels;
    int gridSize;

    void placeItems(Level& level, char item, int count);
};

#endif
