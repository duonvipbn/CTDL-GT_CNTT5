#include <stdio.h>

#define MAX 5

typedef struct {

    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int push(Stack *s, int value) {

    if (s->top == MAX - 1) {
        printf("Ngan xep day! Khong the them %d\n", value);
        return 0;
    }
    s->arr[++(s->top)] = value;

    return 1;
}

void printStack(Stack *s) {

    if (s->top == -1) {
        printf("Ngan xep rong.\n");

        return;
    }
    printf("Cac phan tu trong ngan xep: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }

    printf("\n");
}

int main() {

    Stack myStack;
    initStack(&myStack);

    int value;

    for (int i = 0; i < 5; i++) {
        printf("Nhap so nguyen thu %d: ", i + 1);
        scanf("%d", &value);
        push(&myStack, value);
    }

    printStack(&myStack);

    return 0;
}
