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

Node* insertHead(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int getLength(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void printMiddle(Node* head) {
    int len = getLength(head);
    int midIndex = len / 2;
    Node* current = head;
    int index = 0;
    while (current != NULL) {
        if (index == midIndex) {
            printf("Node %d: %d\n", index + 1, current->data);
            return;
        }
        current = current->next;
        index++;
    }
}

int main() {
    Node* head = NULL;
    head = insertHead(head, 1);
    head = insertHead(head, 2);
    head = insertHead(head, 3);
    head = insertHead(head, 4);
    head = insertHead(head, 5);

    printList(head);
    printMiddle(head);

    head = insertHead(head, 6);

    printList(head);
    printMiddle(head);

    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
