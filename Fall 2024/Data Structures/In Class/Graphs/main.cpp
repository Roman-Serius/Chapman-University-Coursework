#include "UGraph.h"
using namespace std;

int main(){
    UGraph myGraph(4U);
    myGraph.addEdge(0U, 1U);
    myGraph.addEdge(0U, 2U);
    myGraph.addEdge(1U, 2U);
    myGraph.addEdge(2U, 3U);

    cout << myGraph.areAdjacent(1U, 2U) << endl;
    cout << myGraph.areAdjacent(3U, 1U) << endl;

    return 0;
}