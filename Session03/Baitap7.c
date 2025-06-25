#include <stdio.h>

int main() {
    int rows, cols, k;

    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    if (rows <= 0 || rows >= 1000) {
        printf("So hang khong hop le\n");
        return 0;
    }

    if (cols <= 0 || cols >= 1000) {
        printf("So cot khong hop le\n");
        return 0;
    }

    int arr[1000][1000];

    printf("Nhap cac phan tu trong mang:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Nhap chi so hang k muon tinh tong: ");
    scanf("%d", &k);

    if (k < 0 || k >= rows) {
        printf("Hang can tinh khong ton tai\n");
    } else {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += arr[k][j];
        }
        printf("Tong hang thu %d la: %d\n", k, sum);
    }

    return 0;
}
