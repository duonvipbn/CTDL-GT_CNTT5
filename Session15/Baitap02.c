#include <stdio.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

void enqueue(Queue *q, int newValue) {
    if (q->rear == MAX - 1) {
        printf("Hang doi da day\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = newValue;
}

void displayQueue(Queue q) {
    if (q.front > q.rear) {
        printf("Hang doi rong\n");
        return;
    }
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);

    displayQueue(q);

    return 0;
}
