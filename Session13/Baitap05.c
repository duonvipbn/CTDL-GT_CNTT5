#include <stdio.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void init_stack(Stack *s) {
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

void reverse_array(int a[], int n) {
    Stack s;
    init_stack(&s);

    for (int i = 0; i < n; i++) {
        push(&s, a[i]);
    }

    for (int i = 0; i < n; i++) {
        a[i] = pop(&s);
    }
}

void print_array(int a[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int n;
    int a[MAX];

    printf("nhap so phan tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("nhap gia tri phan tu thu %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("mang ban dau:\n");
    print_array(a, n);

    reverse_array(a, n);

    printf("mang sau khi dao nguoc:\n");
    print_array(a, n);

    return 0;
}
