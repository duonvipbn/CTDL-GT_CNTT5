#include <stdio.h>

int sum(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sum(n - 1);
}

int main() {
    int n, c;
    do {
        printf("Nhap vao so nguyen duong:");
        if (scanf("%d", &n) != 1 || n < 1) {
            printf("So khong hop le! nhap lai.\n");
            while ((c = getchar()) != '\n' && c != EOF);
        }else {
            break;
        }
    }while (1);

    int total = sum(n);
    printf("tong: %d", total);

    return 0;
}
