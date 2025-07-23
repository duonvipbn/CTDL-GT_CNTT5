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

void addEdge(int graph[SIZE][SIZE], int startNode, int endNode) {
    graph[startNode][endNode] = 1;
}

int main() {
    int graph[SIZE][SIZE] = {0};

    printMatrix(graph);

    int startNode = 1;
    int endNode = 2;
    addEdge(graph, startNode, endNode);

    printMatrix(graph);

    return 0;
}
