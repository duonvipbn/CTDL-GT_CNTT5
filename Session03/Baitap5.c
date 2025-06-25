#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;

    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    if (rows <= 0 && cols <= 0) {
        printf("So cot va so hang khong hop le\n");
        return 1;
    } else if (rows <= 0) {
        printf("So hang khong hop le\n");
        return 1;
    } else if (cols <= 0) {
        printf("So cot khong hop le\n");
        return 1;
    }

    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Nhap cac phan tu trong mang:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }

    if (rows == cols) {
        int sumMain = 0;
        int sumSub = 0;
        for (int i = 0; i < rows; i++) {
            sumMain += arr[i][i];
            sumSub += arr[i][rows - 1 - i];
        }
        printf("Tong duong cheo chinh = %d\n", sumMain);
        printf("Tong duong cheo phu = %d\n", sumSub);
    } else {
        printf("Khong ton tai duong cheo chinh\n");
        printf("Khong ton tai duong cheo phu\n");
    }

    for (int i = 0; i < rows; i++)
        free(arr[i]);
    free(arr);
    arr = NULL;
    return 0;
}
