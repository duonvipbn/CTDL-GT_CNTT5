#include <stdio.h>

#define MAX 100

void addEdge(int graph[MAX][MAX], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void printGraph(int graph[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int graph[MAX][MAX] = {0};

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d", &u);
        scanf("%d", &v);
        addEdge(graph, u, v);
    }

    printGraph(graph, n);

    return 0;
}
