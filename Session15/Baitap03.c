#include <stdio.h>
#include <stdbool.h>

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

bool isEmpty(Queue *q) {
    return q->rear < q->front;
}

int main() {
    Queue q;
    initQueue(&q);

    if (isEmpty(&q)) {
        printf("ĐÚNG VẬY\n");
    } else {
        printf("SAI\n");
    }

    q.arr[++q.rear] = 1;
    q.arr[++q.rear] = 2;
    q.arr[++q.rear] = 5;

    if (isEmpty(&q)) {
        printf("ĐÚNG VẬY\n");
    } else {
        printf("SAI\n");
    }

    return 0;
}
