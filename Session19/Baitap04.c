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

void printInOrder(Node* node) {
    if (!node) {
        return;
    }
    
    printPostOrder(node->left);
    printf("%d ", node->data);
    printPostOrder(node->right);
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    printInOrder(root);
    return 0;
}

