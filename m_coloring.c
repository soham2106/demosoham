#include <stdio.h>
#define V 4 // Number of vertices in the graph

void printSolution(int color[]);

// Function to check if it is safe to assign the color c to vertex v
int isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i])
            return 0;
    }
    return 1;
}

// Recursive function to solve m-coloring problem
int graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    // Base case: If all vertices are assigned a color, return true
    if (v == V)
        return 1;

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        // Check if assignment of color c to v is valid
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            // Recur to assign colors to rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1) == 1)
                return 1;

            // If assigning color c doesn't lead to a solution, backtrack
            color[v] = 0;
        }
    }

    // If no color can be assigned to this vertex, return false
    return 0;
}

// Main function to solve m-coloring problem using graphColoringUtil function
int graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    // Call graphColoringUtil for vertex 0
    if (graphColoringUtil(graph, m, color, 0) == 0) {
        printf("Solution does not exist");
        return 0;
    }

    // Print the solution
    printSolution(color);
    return 1;
}

// Function to print the solution (color assignment for vertices)
void printSolution(int color[]) {
    printf("Solution exists and the assigned colors are: \n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d --> Color %d\n", i, color[i]);
}

// Driver code
int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3; // Number of colors
    graphColoring(graph, m);
    return 0;
}
