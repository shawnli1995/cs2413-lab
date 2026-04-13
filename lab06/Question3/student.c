#include "graph.h"

// Description

// Check whether the graph contains a triangle. A triangle is a set of three nodes that are all connected to each other. 
// The graph is stored as an adjacency matrix. 
// Graph* g is a pointer to a Graph struct, which contains a 2D array adj[MAX_NODES][MAX_NODES]. 
// The value at adj[u][v] is 1 if there is an edge between nodes u and v, and 0 otherwise.

int has_triangle(Graph* g) {
    // TODO: implement
    // return -1;
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = i + 1; j < MAX_NODES; j++) {
            for (int k = j + 1; k < MAX_NODES; k++) {

                if (g->adj[i][j] == 1 &&
                    g->adj[j][k] == 1 &&
                    g->adj[k][i] == 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
