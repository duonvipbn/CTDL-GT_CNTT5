#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
} Customer;

typedef struct {
    Customer arr[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->rear < q->front;
}

int isFull(Queue *q) {
    return q->rear - q->front + 1 >= MAX;
}

void enqueue(Queue *q, char name[]) {
    if (isFull(q)) {
        printf("Hang doi day\n");
        return;
    }
    q->rear++;
    strcpy(q->arr[q->rear].name, name);
    printf("Da them %s vao hang doi\n", name);
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Khong co khach nao de phuc vu\n");
        return;
    }
    printf("Phuc vu khach hang: %s\n", q->arr[q->front].name);
    q->front++;
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Khong co khach dang cho\n");
        return;
    }
    printf("Danh sach khach dang cho:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("- %s\n", q->arr[i].name);
    }
}

int main() {
    Queue q;
    initQueue(&q);

    int choice;
    char name[NAME_LEN];

    while (1) {
        printf("\nMENU\n");
        printf("1. Them khach hang\n");
        printf("2. Phuc vu khach hang\n");
        printf("3. Hien thi danh sach khach dang cho\n");
        printf("4. Thoat\n");
        printf("Chon thao tac: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhap ten khach hang: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                enqueue(&q, name);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                printf("Thoat chuong trinh\n");
                exit(0);
            default:
                printf("Lua chon khong hop le\n");
        }
    }

    return 0;
}
