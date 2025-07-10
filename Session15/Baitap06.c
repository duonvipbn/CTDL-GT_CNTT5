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

void enqueue(Queue *q, int value) {
    q->arr[++q->rear] = value;
}

int dequeue(Queue *q) {
    return q->arr[q->front++];
}

bool isIncreasingByOne(Queue *q) {
    while (q->rear - q->front >= 1) {
        int a = dequeue(q);
        int b = q->arr[q->front];
        if (b - a != 1) return false;
    }
    return true;
}

int main() {
    Queue q;
    initQueue(&q);

    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    if (isIncreasingByOne(&q)) {
        printf("ĐÚNG VẬY\n");
    } else {
        printf("SAI\n");
    }

    return 0;
}
