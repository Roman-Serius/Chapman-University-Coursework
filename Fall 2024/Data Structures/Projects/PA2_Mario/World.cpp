#include "World.h"
#include <cstdlib>
#include <ctime>

World::World(int numLevels, int gridSize) : numLevels(numLevels), gridSize(gridSize)
{
    if (numLevels <= 0 || gridSize <= 0) {
        cerr << "Error: Invalid number of levels or grid size." << endl;
        return;
    }

    levels = new Level[numLevels];
    for (int i = 0; i < numLevels; ++i) 
    {
        levels[i] = Level(gridSize);  // Ensure gridSize is valid here
    }

    srand(time(0));

}

World::~World() {
    delete[] levels;
}

void World::randomItemPlace(Level &level, char item, int count)
{
    for (int i = 0; i < count; ++i)
    {
        int row = rand() % gridSize;
        int column = rand() % gridSize;

        // Skip placing items in row 0 as a temporary workaround
        while (row == 0) {
            row = rand() % gridSize;  // Regenerate row until it's not 0
        }

        std::cout << "Randomly placing item " << item << " at (" << row << ", " << column << ")" << std::endl;
        level.placeItem(row, column, item);  // Call the placeItem() method
    }
}

void World::populateLevel(int currentLevelNum, int perCoins, int perNothing, int perGoomba, int perKoopa, int perMushroom)
{
    Level &level = levels[currentLevelNum];

    int totalPlaces = gridSize * gridSize;
    int coinCount = (totalPlaces * perCoins) / 100;
    int nothingCount = (totalPlaces * perNothing) / 100;
    int goombaCount = (totalPlaces * perGoomba) / 100;
    int koopaCount = (totalPlaces * perKoopa) / 100;
    int mushroomCount = (totalPlaces * perMushroom) / 100;

    // Call the testGridAccess() function here to test grid memory allocation
    std::cout << "Testing grid access for level " << currentLevelNum + 1 << std::endl;
    level.testGridAccess();

    randomItemPlace(level, 'c', coinCount);
    randomItemPlace(level, 'n', nothingCount);
    randomItemPlace(level, 'g', goombaCount);
    randomItemPlace(level, 'k', koopaCount);
    randomItemPlace(level, 'm', mushroomCount);

    // Place the boss
    int bossRow = rand() % gridSize;
    int bossColumn = rand() % gridSize;
    level.placeItem(bossRow, bossColumn, 'b');
}

void World::displayWorld() const {
    for (int i = 0; i < numLevels; ++i) {
        cout << "Level " << i + 1 << ":" << endl;
        levels[i].display();
        cout << endl;
    }
}