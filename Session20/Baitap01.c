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

    printf("%d\n", root->data);
    printf("%d\n", root->left->data);
    printf("%d\n", root->left->left->data);
    printf("%d\n", root->right->data);

    return 0;
}
