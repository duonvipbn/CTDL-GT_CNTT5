#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
        return 0;
    }
    return s->arr[(s->top)--];
}

int evaluate_postfix(char expr[]) {
    Stack s;
    init_stack(&s);
    int len = strlen(expr);

    for (int i = 0; i < len; i++) {
        char c = expr[i];

        if (isdigit(c)) {
            push(&s, c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int b = pop(&s);
            int a = pop(&s);
            int result = 0;

            if (c == '+') result = a + b;
            else if (c == '-') result = a - b;
            else if (c == '*') result = a * b;
            else if (c == '/') result = a / b;

            push(&s, result);
        }
    }

    return pop(&s);
}

int main() {
    char expr[MAX];

    printf("nhap bieu thuc hau to: ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0';

    int ket_qua = evaluate_postfix(expr);

    printf("gia tri cua bieu thuc la: %d\n", ket_qua);

    return 0;
}
