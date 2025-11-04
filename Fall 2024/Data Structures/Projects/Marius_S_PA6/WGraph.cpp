// Soren Marius  
// 002456139  
// Marius@chapman.edu  
// CPSC-350-01  
// PA6: Spanning the Gamut
#include "WGraph.h"
#include <iostream>
#include <iomanip> // For formatted output

WGraph::WGraph(int numNodes, double** adjacencyMatrix)
    : numNodes(numNodes), adjacencyMatrix(adjacencyMatrix), edges(nullptr), edgeCount(0) {
    extractEdges();
}

void WGraph::extractEdges() {
    edges = new Edge[numNodes * numNodes];
    edgeCount = 0;

    for (int i = 0; i < numNodes; ++i) {
        for (int j = i + 1; j < numNodes; ++j) {
            if (adjacencyMatrix[i][j] > 0.0) {
                Edge newEdge;
                newEdge.u = i;
                newEdge.v = j;
                newEdge.weight = adjacencyMatrix[i][j];
                edges[edgeCount++] = newEdge;
            }
        }
    }
}

void WGraph::sortEdges() {
    // Simple Bubble Sort for sorting edges by weight
    for (int i = 0; i < edgeCount - 1; ++i) {
        for (int j = 0; j < edgeCount - i - 1; ++j) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int WGraph::find(int* parent, int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

void WGraph::unionSets(int* parent, int* rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

void WGraph::computeMST() {
    sortEdges();

    Edge* mstEdges = new Edge[numNodes - 1];
    int* parent = new int[numNodes];
    int* rank = new int[numNodes];
    for (int i = 0; i < numNodes; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }

    int mstEdgeCount = 0;
    double mstCost = 0.0;

    for (int i = 0; i < edgeCount && mstEdgeCount < numNodes - 1; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        double weight = edges[i].weight;

        if (find(parent, u) != find(parent, v)) {
            unionSets(parent, rank, u, v);
            mstEdges[mstEdgeCount++] = edges[i];
            mstCost += weight;
        }
    }

    printMST(mstEdges, mstEdgeCount, mstCost);

    delete[] mstEdges;
    delete[] parent;
    delete[] rank;
}

void WGraph::printMST(Edge* mstEdges, int mstEdgeCount, double mstCost) {
    std::cout << "The MST Cost is: " << mstCost << std::endl;

    double** mstMatrix = new double*[numNodes];
    for (int i = 0; i < numNodes; ++i) {
        mstMatrix[i] = new double[numNodes];
        for (int j = 0; j < numNodes; ++j) {
            mstMatrix[i][j] = 0.0;
        }
    }

    for (int i = 0; i < mstEdgeCount; ++i) {
        int u = mstEdges[i].u;
        int v = mstEdges[i].v;
        double weight = mstEdges[i].weight;
        mstMatrix[u][v] = weight;
        mstMatrix[v][u] = weight;
    }

    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            std::cout << std::fixed << std::setprecision(1) << mstMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < numNodes; ++i) delete[] mstMatrix[i];
    delete[] mstMatrix;
}