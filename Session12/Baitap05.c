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
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteByValue(Node** head, int value) {
    Node* current = *head;
    while (current != NULL) {
        if (current->data == value) {
            Node* toDelete = current;
            if (current->prev != NULL)
                current->prev->next = current->next;
            else
                *head = current->next;
            if (current->next != NULL)
                current->next->prev = current->prev;
            current = current->next;
            free(toDelete);
        } else {
            current = current->next;
        }
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
    append(&head, 5);
    append(&head, 2);
    append(&head, 1);
    append(&head, 5);

    printList(head);

    int value;
    scanf("%d",
