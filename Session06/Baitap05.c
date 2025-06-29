#include <stdio.h>
#include <stdlib.h>

int highestNum(int arr[], int n) {
    if (n == 1) return arr[0];

    int maxSoFar = highestNum(arr, n - 1);
    return (arr[n - 1] > maxSoFar) ? arr[n - 1] : maxSoFar;
}


int lowestNum(int arr[], int n) {
    if (n == 1) return arr[0];

    int minSoFar = lowestNum(arr, n - 1);
    return (arr[n - 1] < minSoFar) ? arr[n - 1] : minSoFar;
}

int main() {
    int n, c;
    do {
        printf("Nhap so luong phan tu trong mang: ");
        if (scanf("%d", &n) != 1 || n < 1) {
            printf("So khong hop le! So luong phan tu phai la so nguyen duong\n");
            while ((c = getchar()) != '\n' && c != EOF);
        } else {
            break;
        }
    } while (1);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong cap phat duoc bo nho\n");
        return 1;
    }

    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        do {
            printf("arr[%d] = ", i);
            if (scanf("%d", &arr[i]) != 1) {
                printf("So khong hop le! Phai la so nguyen.\n");
                while ((c = getchar()) != '\n' && c != EOF);
            } else {
                break;
            }
        } while (1);
    }

    printf("Phan tu lon nhat: %d\n", highestNum(arr, n));
    printf("Phan tu nho nhat: %d\n", lowestNum(arr, n));

    free(arr);
    arr = NULL;
    return 0;
}
