// Soren Marius
// 002456139
// Marius@chapman.edu
// CPSC-350-01
// PA2:

#include "FileProcessor.h"
#include <cstdlib>
#include <fstream>


FileProcessor::FileProcessor() : myfile() {
    cout << "FileProcessor Constructed" << endl;
}

FileProcessor::~FileProcessor() {
    cout << "FileProcessor Deconstructed" << endl;
}

// Opens input file and reads configuration
void FileProcessor::processFile(string input) {
    myfile.open(input);

    if (!myfile.is_open()) {
            cerr << "Error: Could not open file " << input << endl;
            return;
        }

    getline(myfile, numLevels);
    getline(myfile, gridSize);
    getline(myfile, initLives);
    getline(myfile, perCoins);
    getline(myfile, perNothing);
    getline(myfile, perGoomba);
    getline(myfile, perKoopa);
    getline(myfile, perMushroom);
    
    numLevelsInt = stoi(numLevels);
    gridSizeInt = stoi(gridSize);
    initLivesInt = stoi(initLives);
    perCoinsInt = stoi(perCoins);
    perNothingInt = stoi(perNothing);
    perGoombaInt = stoi(perGoomba);
    perKoopaInt = stoi(perKoopa);
    perMushroomInt = stoi(perMushroom);

    myfile.close();
}

void FileProcessor::outputFile(Mario &mario) {
    ofstream output("GAME.txt");
    output << "Mario Lives: " << mario.getLives() << endl;
    output << "Mario Coins: " << mario.getCoins() << endl;
    output << "Mario Power Level: " << mario.getPowerLevel() << endl;
    // Add any other relevant game state information here
}

int FileProcessor::getGridSize(){
    return gridSizeInt;
}

int FileProcessor::getInitLives(){
    return initLivesInt;
}

int FileProcessor::getNumLevels(){
    return numLevelsInt;
}

int FileProcessor::getPerCoins(){
    return perCoinsInt;
}

int FileProcessor::getPerGoomba(){
    return perGoombaInt;
}

int FileProcessor::getPerKoopa(){
    return perKoopaInt;
}

int FileProcessor::getPerMushroom(){
    return perMushroomInt;
}

int FileProcessor::getPerNothing(){
    return perNothingInt;
}






