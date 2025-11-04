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
        delete[] heights[i];
    }
    delete[] heights;
}

void SpeakerView::readFromFile(const char* filename) {
    std::ifstream infile(filename);
    std::string line;

    // Skip BEGIN line
    std::getline(infile, line);

    // Dynamically count rows and columns
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


    infile.clear(); //reset the stream
    infile.seekg(0, std::ios::beg);
    std::getline(infile, line);  // Skip BEGIN again

    // Allocate memory for the heights array
    heights = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        heights[i] = new double[cols];
    }

    // Second pass to fill the array
    int rowIndex = 0;
    while (std::getline(infile, line)) {
        if (line == "END"){
            break;
        }
        std::istringstream iss(line);
        for (int colIndex = 0; colIndex < cols; ++colIndex) {
            iss >> heights[rowIndex][colIndex];
        }
        ++rowIndex;
    }
    
}

void SpeakerView::calculateSpeakerView() {
    for (int col = 0; col < cols; ++col) {
        MonoStack<double> stack(rows, 'd');  // Monotonically decreasing stack
        double* visibleHeights = new double[rows];
        int visibleCount = 0;

        for (int row = 0; row < rows; ++row) {
            double currentHeight = heights[row][col];
            if (stack.isEmpty() || currentHeight > stack.top()) {
                visibleHeights[visibleCount++] = currentHeight;
            }
            stack.push(currentHeight);
        }

        // Output results for this column
        std::cout << "In column " << col << " there are " << visibleCount << " that can see. Their heights are: ";
        for (int i = 0; i < visibleCount; ++i) {
            std::cout << visibleHeights[i] << " inches, ";
        }
        std::cout << std::endl;

        delete[] visibleHeights;  // Clean up memory
    }
}