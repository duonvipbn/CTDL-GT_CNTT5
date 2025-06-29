#include <stdio.h>
#include <stdlib.h>

int recursion(int rows, int cols, int i, int j) {
    if (i >= rows || j >= cols) {
        return 0;
    }
    if (i == rows - 1 && j == cols - 1) {
        return 1;
    }
    return recursion(rows, cols, i + 1, j) + recursion(rows, cols, i, j + 1);
}

int main() {
    int rows, cols, c;
    do {
        printf("Nhap so hang: ");
        if (scanf("%d", &rows) != 1 || rows < 1) {
            printf("So hang khong hop le! Phai la so nguyen duong.\n");
            while ((c = getchar()) != '\n' && c != EOF);
        } else {
            break;
        }
    } while (1);

    do {
        printf("Nhap so cot: ");
        if (scanf("%d", &cols) != 1 || cols < 1) {
            printf("So cot khong hop le! Phai la so nguyen duong.\n");
            while ((c = getchar()) != '\n' && c != EOF);
        } else {
            break;
        }
    } while (1);

    printf("Tong buoc di: %d\n", recursion(rows, cols, 0, 0));

    return 0;
}
