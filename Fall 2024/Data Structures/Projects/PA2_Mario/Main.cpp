#include <iostream>
#include "Mario.h"
#include "World.h"
#include "FileProcessor.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    // Initialize the FileProcessor to read input from the provided file
    FileProcessor fileProcessor;
    fileProcessor.processFile(argv[1]);

    // Extract values from FileProcessor
    int numLevels = fileProcessor.getNumLevels();
    int gridSize = fileProcessor.getGridSize();
    int initialLives = fileProcessor.getInitLives();
    int coinPercentage = fileProcessor.getPerCoins();
    int goombaPercentage = fileProcessor.getPerGoomba();
    int koopaPercentage = fileProcessor.getPerKoopa();
    int mushroomPercentage = fileProcessor.getPerMushroom();
    int nothingPercentage = fileProcessor.getPerNothing();
    cout << numLevels << " " << gridSize << endl;

    // Initialize the World and Mario objects
    World world(numLevels, gridSize);
    Mario mario(initialLives, 0, 0);  // Mario starts with 0 power level

    // Populate each level with random items using percentages
    for (int i = 0; i < numLevels; ++i) {
        world.populateLevel(i, coinPercentage, nothingPercentage, goombaPercentage, koopaPercentage, mushroomPercentage);
    }

    // Display the World
    world.displayWorld();

    return 0;
}