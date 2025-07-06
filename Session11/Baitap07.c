#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

node* createnode(int value) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void printlist(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf("<->");
        current = current->next;
    }
    printf("->null\n");
}

int length(node* head) {
    int count = 0;
    node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

node* insertat(node* head, int value, int pos) {
    if (pos <= 0) return head;
    if (pos == 1) {
        node* newnode = createnode(value);
        newnode->next = head;
        if (head != NULL) head->prev = newnode;
        return newnode;
    }

    node* current = head;
    int i = 1;
    while (current != NULL && i < pos - 1) {
        current = current->next;
        i++;
    }

    if (current == NULL) return head;

    node* newnode = createnode(value);
    newnode->next = current->next;
    newnode->prev = current;

    if (current->next != NULL) current->next->prev = newnode;
    current->next = newnode;

    return head;
}

int main() {
    node* n1 = createnode(1);
    node* n2 = createnode(2);
    node* n3 = createnode(3);
    node* n4 = createnode(4);
    node* n5 = createnode(5);

    n1->next = n2;

    n2->prev = n1;
    n2->next = n3;

    n3->prev = n2;
    n3->next = n4;

    n4->prev = n3;
    n4->next = n5;

    n5->prev = n4;

    printlist(n1);

    int value, pos;
    printf("value: ");
    scanf("%d", &value);
    printf("position: ");
    scanf("%d", &pos);

    n1 = insertat(n1, value, pos);

    printlist(n1);

    return 0;
}
