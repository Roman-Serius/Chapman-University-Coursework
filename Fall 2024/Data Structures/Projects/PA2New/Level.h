// Soren Marius
// 002456139
// Marius@chapman.edu
// CPSC-350-01
// PA2: Not so Super Mario Bros.
#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include "FileProcessor.h"


using namespace std;
class FileProcessor;

class Level { 
    public:

    Level();
    Level(int gridSize);
    ~Level();

    void placeItem(int row, int column, char item);

    void display(FileProcessor& fileProcessor);

    
        FileProcessor* fileProcessor;
        int gridSize;
        char** levelGrid;
};

#endif

