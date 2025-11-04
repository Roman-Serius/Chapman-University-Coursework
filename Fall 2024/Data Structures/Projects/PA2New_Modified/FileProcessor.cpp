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



void FileProcessor::writeToFile( const std::string &data) {
    // Open the file in append mode
    std::ofstream outFile;
    outFile.open("GAME.txt", std::ios::app);  //  new data is appended to the file

    // Check if the file is open
    if (outFile.is_open()) {
        // Write the data to the file, followed by a newline
        outFile << data;

        // Close the file
        outFile.close();
        std::cout << "Data successfully appended" << std::endl;
    } else {
        // Handle error in case the file cannot be opened
        std::cerr << "Error: Could not open file "  << std::endl;
    }
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

