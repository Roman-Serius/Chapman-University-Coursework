#include "PalindromeFinder.h"
#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Please provide the input file name." << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    PalindromeFinder finder;
    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
        if (line == "END") break; // Stop processing at sentinel line
        finder.processSequence(line); // Process each DNA sequence
    }

    inputFile.close();
    return 0;
}