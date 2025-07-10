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

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("hàng đợi trống\n");
        return -1;
    } else {
        return q->arr[q->front++];
    }
}

int main() {
    Queue q;
    initQueue(&q);

    dequeue(&q);

    q.arr[++q.rear] = 1;
    q.arr[++q.rear] = 2;
    q.arr[++q.rear] = 5;

    int value = dequeue(&q);
    if (value != -1) {
        printf("giá trị trả về = %d;\n", value);
    }

    displayQueue(&q);

    return 0;
}
