#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int tong = 0, dem = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            tong += arr[i];
            dem++;
        }
    }

    if (dem == 0) {
        printf("Khong co so chan trong mang\n");
    } else {
        float trungBinh = (float)tong / dem;
        printf("Trung Binh Chan = %.0f\n", trungBinh);
    }

    free(arr);
    arr = NULL;

    return 0;
}
