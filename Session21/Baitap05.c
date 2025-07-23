#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* graph[SIZE];

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* graph[], int u, int v) {
    Node* newNode1 = createNode(v);
    newNode1->next = graph[u];
    graph[u] = newNode1;

    Node* newNode2 = createNode(u);
    newNode2->next = graph[v];
    graph[v] = newNode2;
}

void printGraph(Node* graph[]) {
    for (int i = 0; i < SIZE; i++) {
        printf(" ");
        Node* temp = graph[i];
        if (temp == NULL) {
            printf("NULL");
        } else {
            while (temp) {
                printf("%d", temp->value);
                if (temp->next) printf("->");
                temp = temp->next;
            }
            printf("->NULL");
        }
        printf(",\n");
    }
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        graph[i] = NULL;
    }

    printGraph(graph);

    int startNode = 1, endNode = 2;
    addEdge(graph, startNode, endNode);
    printGraph(graph);

    startNode = 0, endNode = 1;
    addEdge(graph, startNode, endNode);
    printGraph(graph);

    return 0;
}
