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

#define MAX_QUEUE 100

typedef struct {
    Node* items[MAX_QUEUE];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, Node* node) {
    if (q->rear == MAX_QUEUE - 1) return;
    if (isEmpty(q)) q->front = 0;
    q->items[++q->rear] = node;
}

Node* dequeue(Queue* q) {
    if (isEmpty(q)) return NULL;
    Node* temp = q->items[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return temp;
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

int main() {
    int val;
    scanf("%d", &val);
    Node* root = createNode(val);

    scanf("%d", &val);
    root->left = createNode(val);

    scanf("%d", &val);
    root->right = createNode(val);

    scanf("%d", &val);
    root->left->left = createNode(val);

    scanf("%d", &val);
    addValue(root, val);

    printf("%d\n", root->data);
    printf("%d\n", root->left->data);
    printf("%d\n", root->left->left->data);
    printf("%d\n", root->left->right->data);
    printf("%d\n", root->right->data);

    return 0;
}
