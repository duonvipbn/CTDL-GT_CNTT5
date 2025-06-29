#include <stdio.h>

int countWays(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    return countWays(n - 1) + countWays(n - 2);
}

int main() {
    int n, c;
    do {
        printf("Nhap so bac cua cau thang: ");
        if (scanf("%d", &n) != 1 || n < 1) {
            printf("So khong hop le! So bac phai la so nguyen duong!\n");
            while ((c = getchar()) != '\n' && c != EOF);
        } else {
            break;
        }
    } while (1);

    printf("So cach de leo het %d bac la: %d\n", n, countWays(n));

    return 0;
}
