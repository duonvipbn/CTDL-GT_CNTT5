#include <stdio.h>
#include <stdlib.h>

int tongDeQuy(int *arr, int n) {
    if (n == 0) return 0;
    return arr[n - 1] + tongDeQuy(arr, n - 1);
}

int main() {
    int n, c;

    do {
        printf("Nhap so luong phan tu: ");
        if (scanf("%d", &n) != 1 || n < 1) {
            printf("So khong hop le! So luong phan tu phai la so nguyen duong lon hon 0.\n");
            while ((c = getchar()) != '\n' && c != EOF);
        } else {
            break;
        }
    } while (1);

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong cap phat duoc bo nho!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        do {
            printf("Nhap phan tu thu %d: ", i+1);
            if (scanf("%d", &arr[i]) != 1) {
                printf("So khong hop le! Vui long nhap so nguyen.\n");
                while ((c = getchar()) != '\n' && c != EOF);
            } else {
                break;
            }
        } while (1);
    }

    int tong = tongDeQuy(arr, n);
    printf("Tong cac phan tu trong mang la: %d\n", tong);

    free(arr);
    arr = NULL;

    return 0;
}
