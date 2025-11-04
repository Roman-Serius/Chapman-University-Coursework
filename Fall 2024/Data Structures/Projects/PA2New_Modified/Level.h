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
    char** levelGrid;
    void placeItem(int row, int column, char item);

    void display(FileProcessor& fileProcessor);

    private:
        FileProcessor* fileProcessor;
        int gridSize;
        
};

#endif

