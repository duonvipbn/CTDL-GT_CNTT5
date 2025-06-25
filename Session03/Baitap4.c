#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    printf("Nhap hang: ");
    scanf("%d", &rows);

    printf("Nhap cot: ");
    scanf("%d", &cols);

    if (rows <= 0 && cols <= 0) {
        return 1;
    } else if (rows <= 0) {
        return 1;
    } else if (cols <= 0) {
        return 1;
    }

    int **arr = (int **)malloc(rows * sizeof(int *));
    if (arr == NULL) {
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
        if (arr[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(arr[j]);
            }
            free(arr);
            return 1;
        }
    }

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }

    int max = arr[0][0];
    int min = arr[0][0];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > max)
                max = arr[i][j];
            if (arr[i][j] < min)
                min = arr[i][j];
        }

    printf("max = %d\n", max);
    printf("min = %d\n", min);

    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
    arr = NULL;
    return 0;
}
