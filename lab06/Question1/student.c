#include "graph.h"
// Question 1 — Count Number of Edges
// Description

// Write a function that counts how many edges are in an undirected graph.
// The graph is stored as an adjacency matrix. (In this lab, we use an adjacency matrix.)
// Graph* g is a pointer to a Graph struct, which contains a 2D array adj[MAX_NODES][MAX_NODES]. 
// The value at adj[u][v] is 1 if there is an edge between nodes u and v, and 0 otherwise.




int count_edges(Graph* g) {
    // TODO: implement
    // return -1;
    int count = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = i + 1; j < MAX_NODES; j++) {
            if (g->adj[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}



















// Tips:
// Explanation
// The graph is stored as an adjacency matrix. Since the graph is undirected, every edge appears twice in the matrix:

// once at adj[u][v]
// once at adj[v][u]

// So when counting all 1s in the matrix, you must divide the total by 2.
