#include "Level.h"
#include <iostream>

//constructor with initializer list
Level::Level() : gridSize(0), levelGrid(nullptr)
{

}
Level::Level(int gridSize) : gridSize(gridSize), levelGrid(nullptr)
{
    //allocate memory
    levelGrid = new char*[gridSize];
    for(int i = 0; i < gridSize; ++i)
    {
         cout << "Initializing row " << i << endl;
        levelGrid[i] = new char[gridSize];
    }

    for(int i = 0; i < gridSize; ++i)
    {
        for (int j = 0; j < gridSize; ++j)
        {
            levelGrid[i][j] = 'x';
        }
    }
}

Level::~Level() 
{
    for(int i = 0; i < gridSize; ++i)
    {
        delete[] levelGrid[i];
    }
   delete[] levelGrid;
}

void Level::placeItem(int row, int column, char item) 
{
    if (row >= 0 && row < gridSize && column >= 0 && column < gridSize)
    {
        if (row == 0)
        {
            cout << "skip placement" << endl;
            
        }
        else
        {
        levelGrid[row][column] = item;
        }
    }
}

void Level::display(FileProcessor& fileProcessor) {
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            cout << levelGrid[i][j] << " ";  // Print to console
            fileProcessor.writeToFile(std::string(1, levelGrid[i][j]) + " ");
        }
        cout << endl;
        fileProcessor.writeToFile("\n");
         // Write a new line to the file
    }
}