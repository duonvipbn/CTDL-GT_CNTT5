#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, c, findN;
    int flag = -1;
    do {
        printf("Nhap so nguyen n: ");
        if (scanf("%d", &n) != 1 || n < 1) {
            printf("Gia tri nhap khong hop le! Vui long nhap so nguyen >= 1.\n");
            while ((c = getchar()) != '\n' && c != EOF);
        } else {
            break;
        }
    } while (1);

    int* arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong cap phat duoc bo nho!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        do {
            printf("Nhap phan tu %d: ", i+1);

            if (scanf("%d", &arr[i]) != 1) {
                printf("Gia tri nhap khong hop le! Vui long nhap so nguyen.\n");
                while ((c = getchar()) != '\n' && c != EOF);
            } else {
                break;
            }
        } while (1);
    }

    do {
        printf("Nhap phan tu can tim: ");

        if (scanf("%d", &findN) != 1) {
            printf("Gia tri nhap khong hop le! Vui long nhap so nguyen.\n");
            while ((c = getchar()) != '\n' && c != EOF);
        } else {
            break;
        }
    } while (1);


    for (int i = 0; i < n; i++) {
        if (findN == arr[i]) {
                flag = i;
            break;
        }
    }
    if (flag != -1) {
        printf("Phan tu dau tien trong mang giong voi gia tri can nhap la %d \n", findN);
    }else {
        printf("khong tim thay phan tu nao");
    }

    free(arr);
    arr = NULL;

    return 0;
}