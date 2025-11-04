// Soren Marius  
// 002456139  
// Marius@chapman.edu  
// CPSC-350-01  
// PA6: Spanning the Gamut
#include "WGraph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For atof

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile) {
        std::cerr << "Error: Could not open input file." << std::endl;
        return 1;
    }

    int numNodes;
    inputFile >> numNodes;

    double** adjacencyMatrix = new double*[numNodes];
    for (int i = 0; i < numNodes; ++i) {
        adjacencyMatrix[i] = new double[numNodes];
        for (int j = 0; j < numNodes; ++j) {
            inputFile >> adjacencyMatrix[i][j];
        }
    }

    std::string endMarker;
    inputFile >> endMarker;
    if (endMarker != "END") {
        std::cerr << "Error: Input file format is incorrect." << std::endl;
        for (int i = 0; i < numNodes; ++i) delete[] adjacencyMatrix[i];
        delete[] adjacencyMatrix;
        return 1;
    }

    WGraph graph(numNodes, adjacencyMatrix);
    graph.computeMST();

    // Clean up
    for (int i = 0; i < numNodes; ++i) delete[] adjacencyMatrix[i];
    delete[] adjacencyMatrix;

    return 0;
}