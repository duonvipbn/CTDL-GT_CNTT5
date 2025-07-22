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

int findMax(Node* root) {
    if (root == NULL) return -2147483648;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    int max = root->data;
    if (leftMax > max) max = leftMax;
    if (rightMax > max) max = rightMax;
    return max;
}

int main() {
    int val;
    Node* root;

    scanf("%d", &val);
    root = createNode(val);

    scanf("%d", &val);
    root->left = createNode(val);

    scanf("%d", &val);
    root->right = createNode(val);

    scanf("%d", &val);
    root->left->left = createNode(val);

    printf("max value: %d\n", findMax(root));

    return 0;
}
