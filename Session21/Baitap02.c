#include <stdio.h>

#define MAX_VERTICES 4

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

void addEdge(int u, int v) {
    adjacencyMatrix[u][v] = 1;
    adjacencyMatrix[v][u] = 1;
}

void printMatrix() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        printf(" ");
        for (int j = 0; j < MAX_VERTICES; j++) {
            printf("%2d", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printMatrix();

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 3);

    printMatrix();

    return 0;
}
