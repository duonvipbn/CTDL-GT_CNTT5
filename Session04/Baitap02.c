#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int main() {
    int n, c;
    int high, highIndex;

    do {
        printf("Nhap so luong phan tu trong mang (1–100): ");
        if (scanf("%d", &n) != 1 || n < 1 || n > 100) {
            printf("So luong khong hop le! Nhap lai.\n");
            while ((c = getchar()) != '\n' && c != EOF);
        } else {
            break;
        }
    } while (1);

    int* arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho: %s\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        do {
            printf("Nhap phan tu %d: ", i+1);
            if (scanf("%d", &arr[i]) != 1) {
                printf("Phan tu nhap khong hop le! Vui long nhap so nguyen.\n");
                while ((c = getchar()) != '\n' && c != EOF);
            } else {
                break;
            }
        } while (1);
    }

    high = arr[0];
    highIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > high) {
            high = arr[i];
            highIndex = i;
        }
    }

    printf("Phan tu lon nhat dau tien o chi so %d, gia tri = %d\n", highIndex+1, high);

    free(arr);
    arr = NULL;

    return 0;
}
