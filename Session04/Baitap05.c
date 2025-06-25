#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, c;

    do {
        printf("Nhap so luong phan tu: ");
        if (scanf("%d", &n) != 1 || n < 1) {
            printf("Sai so luong phan tu! n phai la so nguyen va >= 1.\n");
            while ((c = getchar()) != EOF && c != '\n');
        } else {
            break;
        }
    } while (1);

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho dong!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        do {
            printf("Nhap phan tu %d: ", i + 1);
            if (scanf("%d", &arr[i]) != 1) {
                printf("Phan tu phai la so nguyen!\n");
                while ((c = getchar()) != EOF && c != '\n');
            } else {
                break;
            }
        } while (1);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int x;
    printf("Nhap gia tri can tim: ");
    while (scanf("%d", &x) != 1) {
        printf("Gia tri can tim phai la so nguyen!\nNhap lai: ");
        while ((c = getchar()) != EOF && c != '\n');
    }

    int left = 0, right = n - 1, found = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x) {
            found = 1;
            break;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found) {
        printf("Phan tu trong mang.\n");
    } else {
        printf("Phan tu khong co trong mang.\n");
    }

    free(arr);
    arr = NULL;

    return 0;
}
