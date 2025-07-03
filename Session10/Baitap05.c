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

Node* deleteByValue(Node* head, int value) {
    while (head != NULL && head->data == value) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    return head;
}

int main() {
    Node* head = NULL;
    head = insertHead(head, 5);
    head = insertHead(head, 1);
    head = insertHead(head, 2);
    head = insertHead(head, 5);
    head = insertHead(head, 3);
    head = insertHead(head, 4);
    head = insertHead(head, 5);

    printList(head);

    int x;
    scanf("%d", &x);
    if (x > 0) {
        head = deleteByValue(head, x);
        printList(head);
    }

    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
