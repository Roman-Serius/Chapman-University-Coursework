//Soren Marius
//002456139
//Marius@chapman.edu
//CPSC-350-01
//PA4: Genetic Palindromes

#include <iostream>
#include <fstream>
#include "PalindromeFinder.h"

bool isValidDNA(const std::string &sequence) {
    for (char c : sequence) {
        if (c != 'A' && c != 'C' && c != 'T' && c != 'G') {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {                //help from chatgpt
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    PalindromeFinder finder;
    while (getline(file, line)) {
        if (line == "END") break;
        if (!isValidDNA(line)) {
            std::cout << line << " - INVALID" << std::endl;
            continue;
        }
        finder.analyzeSequence(line);
    }

    file.close();
    return 0;
}