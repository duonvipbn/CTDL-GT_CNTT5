#include <stdio.h>

#define SIZE 3

void printMatrix(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf(" ");
        for (int j = 0; j < SIZE; j++) {
            printf("%2d", graph[i][j]);
            if (j < SIZE - 1)
                printf(", ");
        }
        printf("\n");
    }
}

void addEdge(int graph[SIZE][SIZE], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

int main() {
    int graph[SIZE][SIZE] = {0};

    printMatrix(graph);

    addEdge(graph, 1, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);

    printMatrix(graph);

    return 0;
}
