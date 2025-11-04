#include "World.h"
#include <cstdlib>
#include <ctime>

World::World(int numLevels, int gridSize) : numLevels(numLevels), gridSize(gridSize)
{
    levels = new Level[numLevels];

    for(int i = 0; i < numLevels; ++i) 
    {
        levels[i] = Level(gridSize);
    }

    srand(time(0));
    cout<< "World Created" << endl;
}


World::~World()
{
    delete[] levels;
}

void World::randomItemPlace(Level &level, char item, int count)
{
    for (int i = 0; i < count; ++i)
    {
        int row = rand() % gridSize;
        int column = rand() % gridSize;

        cout << "attempting to place " << item << " at " << row << "," << column << endl;
        level.placeItem(row,column,item);
    }
}

void World::populateWorld( int perCoins, int perNothing, int perGoomba, int perKoopa, int perMushroom){
    for(int i = 0; i <numLevels; ++i)
   {
    cout<< "populating world" << endl;
    populateLevel(i, perCoins, perNothing, perGoomba, perKoopa, perMushroom);
   }
}

void World::populateLevel(int currentLevelNum, int perCoins, int perNothing, int perGoomba, int perKoopa, int perMushroom)
{
    Level &level = levels[currentLevelNum];

    int totalPlaces = gridSize*gridSize;

    int coinCount = (totalPlaces * perCoins)/100;
    int nothingCount = (totalPlaces * perNothing)/100;
    int goombaCount = (totalPlaces * perGoomba)/100;
    int koopaCount = (totalPlaces * perKoopa)/100;
    int mushroomCount = (totalPlaces * perMushroom)/100;

    randomItemPlace(level, 'c', coinCount);
    randomItemPlace(level, 'g', goombaCount);
    randomItemPlace(level, 'k', koopaCount);
    randomItemPlace(level, 'm', mushroomCount);

    int bossRow = rand()%gridSize;
    int bossColumn = rand()%gridSize;

    level.placeItem(bossRow, bossColumn, 'b');

    if(currentLevelNum < numLevels-1)
    {
        int warpRow = rand()%gridSize;
        int warpColumn = rand()%gridSize;
        level.placeItem(warpRow, warpColumn, 'w');
    }
}

void World::displayWorld(FileProcessor& fileProcessor) {
    for (int i = 0; i < numLevels; ++i) {
        cout << "Level " << i + 1 << ":" << endl;
         // Write the level header to file

        levels[i].display(fileProcessor);  // Display each level and write to file
        cout << endl;
         // Write a new line after each level
    }
}