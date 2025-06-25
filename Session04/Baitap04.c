#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, c;
    int findNum;
    int flag = -1;
    do {
        printf("nhap so luong phan tu:");
        if (scanf("%d", &n) != 1 || n < 1) {
            printf("So luong phan tu khong hop le! phai la so nguyen va lon hon hoac bang 1.\n");
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

    for (int i = 0; i < n; i++ ) {
        do {
            printf("nhap phan tu %d: ", i + 1);
            if (scanf("%d", &arr[i]) != 1) {
                printf("Phan tu khong hop le!\n");
                while ((c = getchar()) != '\n' && c != EOF);
            }else {
                break;
            }
        }while (1);
    }

    do {
        printf("Nhap vao mot so nguyen bat ky:");
        if (scanf("%d", &findNum) != 1) {
            printf("Nhap vao khong hop le!");
            while ((c = getchar()) != '\n' && c != EOF);
        }else {
            break;
        }
    }while (1);

    for (int i = 0; i < n; i++) {
        if (findNum == arr[i]) {
            flag = i;
        }
    }
    if (flag != -1) {
        printf("Chi so cua phan tu cuoi cung trong mang giong voi gia tri da nhap la %d", flag);
    }else {
        printf("Khong tim thay!");
    }
    free(arr);
    arr = NULL;
    return 0;
}