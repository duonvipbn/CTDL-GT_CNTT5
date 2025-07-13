#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q != NULL) {
        q->front = NULL;
        q->rear = NULL;
    }
    return q;
}

Node* createNode() {
    int value;
    scanf("%d", &value);
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->next = NULL;
    }
    return newNode;
}

void enqueue(Queue* q) {
    Node* newNode = createNode();
    if (newNode == NULL) return;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("queue is empty\n");
        return;
    }
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

void printQueue(Queue* q) {
    Node* temp = q->front;
    printf("queue = {\n\nfront->");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n\nrear->");
    if (q->rear != NULL) {
        printf("%d->NULL\n\n", q->rear->data);
    } else {
        printf("NULL\n\n");
    }
    printf("}\n\n");
}

int main() {
    Queue* q = createQueue();
    printQueue(q);
    dequeue(q);

    enqueue(q);
    enqueue(q);
    enqueue(q);
    printQueue(q);

    dequeue(q);
    printQueue(q);

    return 0;
}
