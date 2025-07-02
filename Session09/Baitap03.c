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

int search(Node* head, int target) {
    while (head != NULL) {
        if (head->data == target)
            return 1;
        head = head->next;
    }
    return 0;
}

int main() {
    Node* one = createNode(1);
    Node* two = createNode(2);
    Node* three = createNode(3);
    Node* four = createNode(4);
    Node* five = createNode(5);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;

    Node* head = one;

    Node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    int x;
    printf("Nhap so nguyen duong: ");
    scanf("%d", &x);

    if (search(head, x))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
