#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    Node* one = createNode(3);
    Node* two = createNode(2);
    Node* three = createNode(5);
    Node* four = createNode(42);
    Node* five = createNode(4);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;

    return 0;
}
