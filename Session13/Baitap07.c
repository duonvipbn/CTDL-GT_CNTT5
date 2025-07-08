#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char arr[MAX];
    int top;
} Stack;

void init_stack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char value) {
    if (s->top >= MAX - 1) {
        printf("ngan xep day\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

char pop(Stack *s) {
    if (s->top == -1) {
        return '\0';
    }
    return s->arr[(s->top)--];
}

char peek(Stack *s) {
    if (s->top == -1) {
        return '\0';
    }
    return s->arr[s->top];
}

int is_matching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int is_valid_brackets(char expr[]) {
    Stack s;
    init_stack(&s);
    int len = strlen(expr);

    for (int i = 0; i < len; i++) {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{') {
            push(&s, c);
        } else if (c == ')' || c == ']' || c == '}') {
            char top = pop(&s);
            if (!is_matching(top, c)) {
                return 0;
            }
        }
    }

    if (s.top == -1)
        return 1;
    else
        return 0;
}

int main() {
    char expr[MAX];

    printf("nhap bieu thuc: ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0';

    if (is_valid_brackets(expr)) {
        printf("bieu thuc hop le\n");
    } else {
        printf("bieu thuc khong hop le\n");
    }

    return 0;
}
