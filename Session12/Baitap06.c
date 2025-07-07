#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void append(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

int getLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void findMiddle(Node* head) {
    int len = getLength(head);
    int middleIndex = len / 2 + 1;
    int count = 1;
    Node* temp = head;
    while (temp != NULL) {
        if (count == middleIndex) {
            printf("Node %d: %d\n", count, temp->data);
            return;
        }
        count++;
        temp = temp->next;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf("<->");
        temp = temp->next;
    }
    printf("->NULL\n");
}

int main() {
    Node* head = NULL;

    append(&head, 5);
    append(&head, 4);
    append(&head, 3);
    append(&head, 2);
    append(&head, 1);

    printList(head);
    findMiddle(head);

    append(&head, 6);
    printList(head);
    findMiddle(head);

    return 0;
}
