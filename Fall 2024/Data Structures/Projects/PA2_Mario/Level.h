#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>

using namespace std;

class Level 
{ 
     public:
        Level(int gridSize);
        Level();
        ~Level();

        void placeItem(int row, int column, char item);
        void display() const;

        // Add this declaration for testGridAccess
        void testGrid() const;
        void testGridAccess() const;

    private:
        int gridSize;
        char** levelGrid;
};

#endif

