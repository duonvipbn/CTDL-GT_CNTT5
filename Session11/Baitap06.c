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

node* deletehead(node* head) {
    if (head == NULL) return NULL;
    node* temp = head->next;
    if (temp != NULL) temp->prev = NULL;
    free(head);
    return temp;
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

    n1 = deletehead(n1);

    printlist(n1);

    return 0;
}
