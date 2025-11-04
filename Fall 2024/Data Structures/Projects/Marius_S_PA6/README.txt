Soren Marius  
002456139  
Marius@chapman.edu  
CPSC-350-01  
 PA6: Spanning the Gamut

Overview
--------
This program calculates the Minimum Spanning Tree (MST) of an undirected, weighted graph using Kruskal's Algorithm.
The MST minimizes the total edge weight while connecting all nodes without forming cycles.


Input Format
------------
The input file must follow this format:
1. First line: An integer N, the number of nodes in the graph.
2. Next N lines: An N x N adjacency matrix of edge weights.
   - A weight of 0.0 indicates no edge between two nodes.
3. Final line: The string "END".

Example Input File:
4
0.0 2.0 0.0 6.0
2.0 0.0 3.0 8.0
0.0 3.0 0.0 0.0
6.0 8.0 0.0 0.0
END

Output
------
The program outputs:
1. The MST Cost: The total weight of all edges in the MST.
2. Adjacency Matrix: An N x N matrix where only edges in the MST are non-zero.

Example Output:
The MST Cost is: 11.0
0.0 2.0 0.0 6.0 
2.0 0.0 3.0 0.0 
0.0 3.0 0.0 0.0 
6.0 0.0 0.0 0.0 

Files
-----
The program consists of the following files:
1. main.cpp: Handles input, initializes the graph, and runs the MST computation.
2. WGraph.h: Header file defining the graph structure and methods.
3. WGraph.cpp: Implements the graph operations and Kruskal's algorithm.

Compilation
-----------
To compile the program, use the following command:
g++ main.cpp WGraph.cpp -o PA6

Running the Program
-------------------
Run the program with an input file as an argument:
./PA6 input.txt
Replace input.txt with the path to your input file.

How It Works
------------
1. Input Parsing: Reads the number of nodes and the adjacency matrix into a 2D array.
2. Edge Extraction: Converts the adjacency matrix into a list of edges.
3. Sorting: Sorts the edges in ascending order by weight.
4. Kruskal's Algorithm:
   - Iterates through the sorted edges.
   - Adds edges to the MST if they connect disjoint sets.
   - Stops when N-1 edges are included in the MST.
5. Output: Prints the MST cost and the adjacency matrix representation of the MST.

