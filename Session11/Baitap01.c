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

int main() {
    node* n1 = createnode(10);
    node* n2 = createnode(20);
    node* n3 = createnode(30);
    node* n4 = createnode(40);
    node* n5 = createnode(50);

    n1->next = n2;

    n2->prev = n1;
    n2->next = n3;

    n3->prev = n2;
    n3->next = n4;

    n4->prev = n3;
    n4->next = n5;

    n5->prev = n4;

    node* current = n1;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}
