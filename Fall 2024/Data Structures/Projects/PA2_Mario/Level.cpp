#include "Level.h"

// Constructor with initializer list
Level::Level() : gridSize(0), levelGrid(nullptr) {}

Level::Level(int gridSize) : gridSize(gridSize)
{
    std::cout << "Initializing level with grid size: " << gridSize << std::endl;

    // Allocate memory for the 2D grid
    levelGrid = new char*[gridSize];  // Create array for rows
    for (int i = 0; i < gridSize; ++i)
    {
        levelGrid[i] = new char[gridSize];  // Create columns
        if (levelGrid[i] == nullptr)
        {
            std::cerr << "Memory allocation failed for row " << i << std::endl;
        }
        else
        {
            std::cout << "Row " << i << " allocated successfully" << std::endl;
        }
    }

    // Initialize the grid with default values
    for (int i = 0; i < gridSize; ++i)
    {
        for (int j = 0; j < gridSize; ++j)
        {
            levelGrid[i][j] = 'x';  // Default value for all cells
        }
    }
}

Level::~Level()
{
    for (int i = 0; i < gridSize; ++i)
    {
        if (levelGrid[i] != nullptr)
        {
            std::cout << "Freeing row " << i << std::endl;
            delete[] levelGrid[i];  // Free each row
            levelGrid[i] = nullptr; // Set pointer to null to prevent double delete
        }
        else
        {
            std::cerr << "Warning: Row " << i << " was already uninitialized!" << std::endl;
        }
    }

    if (levelGrid != nullptr)
    {
        std::cout << "Freeing levelGrid" << std::endl;
        delete[] levelGrid;  // Free the array of pointers
        levelGrid = nullptr; // Set pointer to null to prevent double delete
    }
}

void Level::placeItem(int row, int column, char item)
{
    if (row >= 0 && row < gridSize && column >= 0 && column < gridSize)
    {
        if (levelGrid[row] == nullptr)
        {
            std::cerr << "Error: Row " << row << " is corrupted or uninitialized!" << std::endl;
            return;
        }

        levelGrid[row][column] = item;
        std::cout << "Item placed successfully at (" << row << ", " << column << ")" << std::endl;
    }
    else
    {
        std::cerr << "Error: Invalid row or column (" << row << ", " << column << ")" << std::endl;
    }
}

void Level::display() const
{
    for (int i = 0; i < gridSize; ++i)
    {
        if (i == 0)  // Skip row 0 as a temporary workaround
        {
            std::cerr << "Skipping row 0 due to corruption." << std::endl;
            continue;
        }

        for (int j = 0; j < gridSize; ++j)
        {
            if (levelGrid[i] == nullptr)
            {
                std::cerr << "Error: Row " << i << " is corrupted or uninitialized." << std::endl;
                return;
            }

            std::cout << levelGrid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Level::testGridAccess() const
{
    // Test if row 0 and other rows are accessible
    for (int i = 0; i < gridSize; ++i)
    {
        std::cout << "Accessing row " << i << std::endl;
        if (levelGrid[i] == nullptr) {
            std::cerr << "Row " << i << " is uninitialized or corrupted!" << std::endl;
        }
    }
}

void Level::testGrid() const
{
    // Output the entire grid to check for any issues
    for (int i = 0; i < gridSize; ++i)
    {
        for (int j = 0; j < gridSize; ++j)
        {
            std::cout << levelGrid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}