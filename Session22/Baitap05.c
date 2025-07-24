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

void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjacencyList[u];
    adjacencyList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjacencyList[v];
    adjacencyList[v] = newNode;
}

int countAdjacent(int k) {
    int count = 0;
    Node* temp = adjacencyList[k];
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int n, v;
    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &v);

    for (int i = 0; i < n; i++) {
        adjacencyList[i] = NULL;
    }

    printf("Nhap cac canh:\n");
    for (int i = 0; i < v; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        addEdge(u, w);
    }

    int k;
    printf("Nhap dinh k muon kiem tra: ");
    scanf("%d", &k);

    int result = countAdjacent(k);
    printf("So dinh ke voi %d la: %d\n", k, result);

    return 0;
}
