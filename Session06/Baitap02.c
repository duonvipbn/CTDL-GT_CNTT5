#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n, c;

    do {
        printf("nhap so nguyen duong bat ky:");
        if (scanf("%d", &n) != 1 || n < 1) {
            printf("So khong hop le! phai la so nguyen duong.");
            while ((c = getchar()) != '\n' &&  c != EOF);
        }else {
            break;
        }
    }while (1);

    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}