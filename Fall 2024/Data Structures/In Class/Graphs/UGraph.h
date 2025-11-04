#ifndef UGRAPH_H
#define UGRAPH_H

#include <cstdlib>
#include <iostream>

//an unweighted, undirected implementation with an adjacency matrix
//fixed size

typedef unsigned int VertexID; //creates a type "VertexID" which acts like an unsigned int

class UGraph{
    public:
        UGraph();
        UGraph(unsigned int sz);
        ~UGraph();
        void addEdge(VertexID i, VertexID j);
        void removeEdge(VertexID i, VertexID j);
        bool areAdjacent(VertexID i, VertexID j);

    private:
        VertexID** m_adj;
        unsigned int m_size;
};

#endif
