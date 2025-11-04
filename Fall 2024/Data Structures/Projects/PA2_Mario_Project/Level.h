#ifndef LEVEL_H
#define LEVEL_H

class Level {
public:
    Level(int size);
    ~Level();

    void placeItem(int row, int column, char item);
    void display() const;
    char getItem(int row, int column) const;

private:
    int gridSize;
    char** grid;  // 2D array representing the level
};

#endif
