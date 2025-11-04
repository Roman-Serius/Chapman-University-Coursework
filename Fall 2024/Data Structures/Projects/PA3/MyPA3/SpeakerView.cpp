//Soren Marius
//002456139
//Marius@chapman.edu
//CPSC-350-01
//PA3: Do You See What I See?
#include "SpeakerView.h"
#include "MonoStack.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

SpeakerView::SpeakerView(const char* filename) {
    readFromFile(filename);
}

SpeakerView::~SpeakerView() {
    for (int i = 0; i < rows; ++i) {
        if (heights[i] != nullptr){
            if (heights[i] == nullptr) {
                std::cerr << "Warning: heights[" << i << "] is nullptr, skipping delete." << std::endl;
                continue;
            }
            delete[] heights[i];
        }
    }
    if (heights != nullptr){
        delete[] heights;
    }
}

void SpeakerView::readFromFile(const char* filename){
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    std::string line;

    std::getline(infile, line);

    rows = 0;
    cols = 0;

    // First pass to calculate rows and columns
    while (std::getline(infile, line)) {
        if (line == "END") {
            break;
        }
        if (rows == 0) {
            std::istringstream iss(line);
            double value;
            while (iss >> value) {
                ++cols;  // Count number of columns from the first row
            }
        }
        ++rows;
    }

    infile.close(); 

    // Reopen the file for the second pass
    infile.open(filename);

    // Skip the "BEGIN" line again
    std::getline(infile, line);

    // Allocate memory for the heights array
    heights = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        heights[i] = new double[cols];
    }

    int rowIndex = 0;
    while (std::getline(infile, line)) {
        if (line == "END"){
            break;
        }
        std::istringstream iss(line);

        // Bounds checking for rowIndex
        if (rowIndex >= rows) {
            std::cerr << "Error: rowIndex exceeds allocated rows." << std::endl;
            return;
        }

        for (int colIndex = 0; colIndex < cols; ++colIndex) {

            // Bounds checking for colIndex
            if (colIndex >= cols) {
                std::cerr << "Error: colIndex exceeds allocated cols." << std::endl;
                return;
            }

            iss >> heights[rowIndex][colIndex];
        }
        ++rowIndex;
    }
}

void SpeakerView::calculateSpeakerView(){    
    // Check if heights array is properly allocated before using it
    if (heights == nullptr) {
        std::cerr << "Error: heights array is not allocated properly." << std::endl;
        return;
    }

    for(int j=0; j<cols; j++){
        MonoStack<double> stack(rows, 'd');
        double* visibleHeights = new double[rows];
        int visibleCount = 0;

        for(int i=0; i<rows; i++){
            double currentHeight = heights[i][j];

            if (stack.isEmpty() || currentHeight > stack.top()) {
                visibleHeights[visibleCount++] = currentHeight;
            }
            stack.push(currentHeight);
        }

        std::cout << "In column " << j << " there are " << visibleCount << " that can see. Their heights are: ";
        for (int i = 0; i < visibleCount; ++i) {
            std::cout << visibleHeights[i] << " inches, ";
        }
        std::cout << std::endl;

        if(visibleHeights != nullptr){
            delete[] visibleHeights; 
        } // Clean up memory
    }
}