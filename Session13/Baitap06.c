#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
        printf("ngan xep rong\n");
        return '\0';
    }
    return s->arr[(s->top)--];
}

bool is_palindrome(char str[]) {
    Stack s;
    init_stack(&s);
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    for (int i = 0; i < len; i++) {
        if (str[i] != pop(&s)) {
            return false;
        }
    }

    return true;
}

int main() {
    char str[MAX];

    printf("nhap chuoi: ");
    fgets(str, MAX, stdin);

    str[strcspn(str, "\n")] = '\0';

    if (is_palindrome(str)) {
        printf("chuoi doi xung\n");
    } else {
        printf("chuoi khong doi xung\n");
    }

    return 0;
}
