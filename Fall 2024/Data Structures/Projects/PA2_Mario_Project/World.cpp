#include "World.h"
#include <cstdlib>
#include <ctime>

World::World(int levels, int size) : numLevels(levels), gridSize(size) {
    levels = new Level*[numLevels];
    for (int i = 0; i < numLevels; ++i) {
        levels[i] = new Level(gridSize);
    }
    srand(time(0));  // Initialize random seed
}

World::~World() {
    for (int i = 0; i < numLevels; ++i) {
        delete levels[i];
    }
    delete[] levels;
}

void World::placeItems(Level& level, char item, int count) {
    int placed = 0;
    while (placed < count) {
        int row = rand() % gridSize;
        int col = rand() % gridSize;
        if (level.getItem(row, col) == 'x') {
            level.placeItem(row, col, item);
            placed++;
        }
    }
}

void World::populateLevel(int level, int coinPercentage, int goombaPercentage, int koopaPercentage, int mushroomPercentage) {
    Level& currentLevel = *levels[level];
    int totalSpaces = gridSize * gridSize;
    
    placeItems(currentLevel, 'c', (coinPercentage * totalSpaces) / 100);
    placeItems(currentLevel, 'g', (goombaPercentage * totalSpaces) / 100);
    placeItems(currentLevel, 'k', (koopaPercentage * totalSpaces) / 100);
    placeItems(currentLevel, 'm', (mushroomPercentage * totalSpaces) / 100);
    
    // Place boss and warp pipe (if needed)
    currentLevel.placeItem(rand() % gridSize, rand() % gridSize, 'b');
    if (level < numLevels - 1) {
        currentLevel.placeItem(rand() % gridSize, rand() % gridSize, 'w');
    }
}

void World::displayWorld() const {
    for (int i = 0; i < numLevels; ++i) {
        std::cout << "Level " << i + 1 << ":" << std::endl;
        levels[i]->display();
        std::cout << std::endl;
    }
}
