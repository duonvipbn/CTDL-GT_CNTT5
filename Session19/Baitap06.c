#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

#define MAX 100
typedef struct Queue {
    Node* items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

void enqueue(Queue* q, Node* node) {
    if (q->rear < MAX) {
        q->items[q->rear++] = node;
    }
}

Node* dequeue(Queue* q) {
    if (q->front < q->rear) {
        return q->items[q->front++];
    }
    return NULL;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

int findValueBFS(Node* root, int value) {
    if (root == NULL) return 0;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);
        if (current->data == value) return 1;

        if (current->left != NULL)
            enqueue(&q, current->left);
        if (current->right != NULL)
            enqueue(&q, current->right);
    }

    return 0;
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int valueToFind = 3;
    printf("findValue: %d\n", valueToFind);
    printf(findValueBFS(root, valueToFind) ? "true\n" : "false\n");

    return 0;
}
