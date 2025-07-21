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

int treeHeight(Node* root) {
    if (root == NULL) return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    root->left->right = createNode(6);

    printf("Height of tree: %d\n", treeHeight(root));

    return 0;
}
