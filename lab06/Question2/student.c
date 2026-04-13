#include "graph.h"
// Description

// Write a function that counts how many nodes are isolated.
// A node is isolated if it has no edges connected to it.
// // The graph is stored as an adjacency matrix. 
// Graph* g is a pointer to a Graph struct, which contains a 2D array adj[MAX_NODES][MAX_NODES]. 
// The value at adj[u][v] is 1 if there is an edge between nodes u and v, and 0 otherwise.




int count_isolated(Graph* g) {
    // TODO: implement
    // return -1;
    int isolated = 0;
    for (int i = 0; i < MAX_NODES; i++) {

        int has_edge = 0;

        for (int j = 0; j < MAX_NODES; j++) {
            if (g->adj[i][j] == 1) {
                has_edge = 1;
                break;
            }
        }

        if (!has_edge) {
            isolated++;
        }
    }
    return isolated;
}















// Tip: In the adjacency matrix, that means the entire row for that node contains only 0s.
