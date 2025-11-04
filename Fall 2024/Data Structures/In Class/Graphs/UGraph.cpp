#include "UGraph.h"

UGraph::UGraph(){
    m_size = 0;
    m_adj = NULL;
}

UGraph::UGraph(unsigned int sz){
    m_size = sz;
    //allocate a sz* sz adj matrix (2d array)
    m_adj = new VertexID*[sz];
    for(int i = 0; i < m_size; ++i){
        m_adj[i] = new VertexID[sz];
    }
    //initialize matrix with edges with no connection
    for(int i = 0; i < m_size; ++i){
        for(int j = 0; j < m_size; ++j){
            m_adj[i][j] = 0U;
        }
    }
}

UGraph::~UGraph(){
    //release memory
}

void UGraph::addEdge(VertexID i,VertexID j){
    if(i < m_size && j < m_size){
        m_adj[i][j] = 1U;
        m_adj[j][i] = 1U;
    }
}

void UGraph::removeEdge(VertexID i,VertexID j){
    if(i < m_size && j < m_size){
        m_adj[i][j] = 0U;
        m_adj[j][i] = 0U;
    }
}

bool UGraph::areAdjacent(VertexID i, VertexID j){
    return (m_adj[i][j] = 1U);
}