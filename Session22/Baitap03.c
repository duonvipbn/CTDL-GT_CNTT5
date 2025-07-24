#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjacencyList[MAX];

Node* createNode(int v) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjacencyList[u];
    adjacencyList[u] = newNode;
}

void convertMatrixToList(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        adjacencyList[i] = NULL;
        for (int j = n - 1; j >= 0; j--) {
            if (matrix[i][j] == 1) {
                addEdge(i, j);
            }
        }
    }
}

void printAdjacencyList(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node* temp = adjacencyList[i];
        while (temp != NULL) {
            printf(" %d ->", temp->vertex);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

int main() {
    int n;
    int matrix[MAX][MAX];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    convertMatrixToList(matrix, n);
    printAdjacencyList(n);

    return 0;
}
