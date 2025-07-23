#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 5
typedef struct Node {
    int value;
    struct Node* next;

} Node;

Node* adjacency[MAX_LEN];

Node* createNode(int pValue) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = pValue;
    temp->next = NULL;
    return temp;
}


Node* createAdjacency(int u, int v) {
    Node* newNode = createNode(u);
    newNode->next = adjacency[u];
    adjacency[u] = newNode;

    newNode = createNode(v);
    newNode->next = adjacency[v];
    adjacency[v] = newNode;

}


void printAdjacency() {
    for (int i = 0; i < MAX_LEN; i++) {
        printf("Adjacency list %d: ", i);
        Node* current = adjacency[i];
        while (current != NULL) {
            printf("%d -> ", current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    for (int i =0; i < MAX_LEN; i++) {
        adjacency[i] = NULL;
    }

    createAdjacency(0, 1);
    createAdjacency(1, 2);
    createAdjacency(1, 2);
    printAdjacency();

    return 0;
}