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

void addValue(Node* root, int value) {
    if (root == NULL) return;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);

        if (current->left == NULL) {
            current->left = createNode(value);
            return;
        } else {
            enqueue(&q, current->left);
        }

        if (current->right == NULL) {
            current->right = createNode(value);
            return;
        } else {
            enqueue(&q, current->right);
        }
    }
}

void printPostOrder(Node* root) {
    if (root == NULL) return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int valueToAdd = 6;
    printf("addValue: %d\n", valueToAdd);
    addValue(root, valueToAdd);

    printf("Cay hau tu (Post-order): ");
    printPostOrder(root);
    printf("\n");

    return 0;
}
