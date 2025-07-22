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

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

QueueNode* front = NULL;
QueueNode* rear = NULL;

void enqueue(Node* t) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = t;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

Node* dequeue() {
    if (front == NULL) return NULL;
    QueueNode* temp = front;
    Node* t = temp->treeNode;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    return t;
}

int isEmpty() {
    return front == NULL;
}

void levelorder(Node* root) {
    if (root == NULL) return;
    enqueue(root);
    while (!isEmpty()) {
        Node* current = dequeue();
        printf("%d ", current->data);
        if (current->left != NULL) enqueue(current->left);
        if (current->right != NULL) enqueue(current->right);
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

    preorder(root);
    printf("\n");

    inorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    levelorder(root);
    printf("\n");

    return 0;
}
