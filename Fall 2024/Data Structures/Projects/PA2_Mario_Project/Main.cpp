#include <iostream>
#include "Mario.h"
#include "World.h"

int main() {
    int numLevels = 3;
    int gridSize = 5;
    int initialLives = 3;

    World world(numLevels, gridSize);
    
    // Populate each level with random items (percentages for coins, Goombas, etc.)
    world.populateLevel(0, 20, 30, 10, 20);
    world.populateLevel(1, 25, 20, 15, 25);
    world.populateLevel(2, 30, 15, 20, 15);
    
    Mario mario(initialLives, 0);  // Mario starts with 3 lives and power level 0

    world.displayWorld();

    return 0;
}
