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

Node* insertAtPosition(Node* head, int value, int position) {
    Node* newNode = createNode(value);
    if (position == 0 || head == NULL) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    int i = 0;
    while (i < position - 1 && current->next != NULL) {
        current = current->next;
        i++;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
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

    printList(head);

    int value, position;
    printf("Nhap gia tri can them: ");
    scanf("%d", &value);
    printf("Nhap vi tri muon them (bat dau tu 0): ");
    scanf("%d", &position);

    head = insertAtPosition(head, value, position);

    printList(head);

    return 0;
}
