#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    printf("Nhap so luong phan tu ban dau (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho\n");
        return 1;
    }

    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Nhap so luong phan tu can them (m): ");
    scanf("%d", &m);

    if (m > 0) {
        arr = (int *)realloc(arr, (n + m) * sizeof(int));
        if (arr == NULL) {
            printf("Khong the cap phat lai bo nho\n");
            return 1;
        }

        printf("Nhap %d phan tu them vao:\n", m);
        for (int i = 0; i < m; i++) {
            printf("arr[%d] = ", n + i);
            scanf("%d", &arr[n + i]);
        }
    }

    printf("Mang sau khi them phan tu: ");
    for (int i = 0; i < n + m; i++) {
        printf("%d", arr[i]);
        if (i < n + m - 1) printf(", ");
    }

    free(arr);
    arr = NULL;
    return 0;
}
