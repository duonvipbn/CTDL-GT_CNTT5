#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjacencyList[MAX];

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* graph[], int u, int v) {

    Node* newNode = createNode(v);
    newNode->next = graph[u];
    graph[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph[v];
    graph[v] = newNode;
}

void printGraph(Node* graph[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node* temp = graph[i];
        while (temp != NULL) {
            printf(" %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        adjacencyList[i] = NULL;
    }

    int u, v;
    while (scanf("%d %d", &u, &v) == 2) {
        addEdge(adjacencyList, u, v);
    }

    printGraph(adjacencyList, n);

    return 0;
}
