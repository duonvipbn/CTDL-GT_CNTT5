#include <stdio.h>

#define MAX 5

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}
int main() {
    Stack myStack;
    initStack(&myStack);

    return 0;
}