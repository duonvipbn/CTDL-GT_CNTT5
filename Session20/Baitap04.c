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

int countLeaves(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
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

    printf("number of leaves: %d\n", countLeaves(root));

    return 0;
}
