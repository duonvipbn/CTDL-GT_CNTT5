#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, c;

    do {
        printf("Nhap so luong phan tu n:");
        if (scanf("%d", &n) != 1 || n < 1) {

            printf("So luong phan tu khong hop le! So luong phan tu phai la so nguyen >= 1\n");
            while ((c = getchar()) != '\n' && c != EOF);
        }else {
            break;
        }

    }while (1);

    int* arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Khong the cap phat bo nho dong\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        do {
            printf("nhap phan tu %d: ", i + 1);
            if (scanf("%d", &arr[i]) != 1) {
                printf("So luong phan tu khong hop le! So luong phan tu phai la so nguyen");
                while ((c = getchar()) != '\n' && c != EOF);
            }else {
                break;
            }
        }while (1);
    }
    int lowNum = arr[0];
    int lowIndexNum = 0;

    for (int i = 0; i < n; i++) {
        if (lowNum > arr[i]) {
            lowNum = arr[i];
            lowIndexNum = i;
        }
    }
    printf("Chi so cua phan tu nho nhat dau tien trong mang la %d", lowIndexNum);

    free(arr);
    arr = NULL;

    return 0;
}