#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    int age;
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

void enqueue(Queue *q, char name[], int age) {
    if (isFull(q)) {
        printf("Hang doi day\n");
        return;
    }
    q->rear++;
    strcpy(q->arr[q->rear].name, name);
    q->arr[q->rear].age = age;
    printf("Da them %s (%d tuoi) vao hang doi\n", name, age);
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Hang doi rong\n");
        return;
    }
    printf("Phuc vu: %s (%d tuoi)\n", q->arr[q->front].name, q->arr[q->front].age);
    q->front++;
}

void displayQueue(Queue *q, char *tenHang) {
    if (isEmpty(q)) {
        printf("%s rong\n", tenHang);
        return;
    }
    printf("%s:\n", tenHang);
    for (int i = q->front; i <= q->rear; i++) {
        printf("- %s (%d tuoi)\n", q->arr[i].name, q->arr[i].age);
    }
}

int main() {
    Queue queueOld, queueNormal;
    initQueue(&queueOld);
    initQueue(&queueNormal);

    int choice;
    char name[NAME_LEN];
    int age;

    while (1) {
        printf("\nMENU\n");
        printf("1. Them khach hang\n");
        printf("2. Phuc vu khach hang\n");
        printf("3. Hien thi hang doi\n");
        printf("4. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhap ten: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Nhap tuoi: ");
                scanf("%d", &age);
                getchar();
                if (age >= 60)
                    enqueue(&queueOld, name, age);
                else
                    enqueue(&queueNormal, name, age);
                break;
            case 2:
                if (!isEmpty(&queueOld))
                    dequeue(&queueOld);
                else if (!isEmpty(&queueNormal))
                    dequeue(&queueNormal);
                else
                    printf("Khong co khach nao dang cho\n");
                break;
            case 3:
                displayQueue(&queueOld, "Hang uu tien");
                displayQueue(&queueNormal, "Hang thong thuong");
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
