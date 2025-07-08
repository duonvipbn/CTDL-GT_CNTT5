#include <stdio.h>

#define MAX 5

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int value) {
    if (s->top >= MAX - 1) {
        printf("ngan xep day\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("ngan xep rong\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

int main() {
    Stack myStack;
    initStack(&myStack);

    myStack.arr[0] = 10;
    myStack.arr[1] = 20;
    myStack.arr[2] = 30;
    myStack.arr[3] = 40;
    myStack.arr[4] = 50;
    myStack.top = 4;

    int value = pop(&myStack);
    if (value != -1) {
        printf("gia tri lay ra: %d\n", value);
    }

    return 0;
}
