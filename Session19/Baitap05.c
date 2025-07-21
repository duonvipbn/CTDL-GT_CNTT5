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

int findValue(Node* root, int value) {
    if (root == NULL) return 0;

    if (root->data == value) return 1;

    return findValue(root->left, value) || findValue(root->right, value);
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int pValFind = 3;
    int found = findValue(root, pValFind);

    printf("findValue: %d\n", pValFind);
    printf(found ? "true\n" : "false\n");
    return 0;
}

