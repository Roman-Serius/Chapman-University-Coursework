#include "Level.h"
#include <iostream>
#include <cstdlib>

Level::Level(int size) : gridSize(size) {
    grid = new char*[gridSize];
    for (int i = 0; i < gridSize; ++i) {
        grid[i] = new char[gridSize];
        for (int j = 0; j < gridSize; ++j) {
            grid[i][j] = 'x';  // Default empty space
        }
    }
}

Level::~Level() {
    for (int i = 0; i < gridSize; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

void Level::placeItem(int row, int column, char item) {
    grid[row][column] = item;
}

char Level::getItem(int row, int column) const {
    return grid[row][column];
}

void Level::display() const {
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
