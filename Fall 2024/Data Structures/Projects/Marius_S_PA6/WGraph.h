// Soren Marius  
// 002456139  
// Marius@chapman.edu  
// CPSC-350-01  
// PA6: Spanning the Gamut
#ifndef WGRAPH_H
#define WGRAPH_H

class WGraph {
public:
    WGraph(int numNodes, double** adjacencyMatrix);
    void computeMST();

private:
    int numNodes;
    double** adjacencyMatrix;

    struct Edge {
        int u, v;
        double weight;
    };

    Edge* edges;
    int edgeCount;

    void extractEdges();
    void sortEdges();
    int find(int* parent, int i);
    void unionSets(int* parent, int* rank, int x, int y);
    void printMST(Edge* mstEdges, int mstEdgeCount, double mstCost);
};

#endif