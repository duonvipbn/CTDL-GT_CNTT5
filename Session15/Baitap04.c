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

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("hàng đợi trống\n");
    } else {
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d\n", q->arr[i]);
        }
    }
}

int main() {
    Queue q;
    initQueue(&q);

    displayQueue(&q);

    q.arr[++q.rear] = 1;
    q.arr[++q.rear] = 2;
    q.arr[++q.rear] = 5;

    displayQueue(&q);

    return 0;
}
