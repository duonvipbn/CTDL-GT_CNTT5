#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    do {
        printf("nhap so luong phan tu n: ");
    } while (scanf("%d", &n) != 1 || n < 1);

    int *myArr = malloc(n * sizeof *myArr);
    if (!myArr) {
        perror("khong the cap phap bo nho dong");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("nhap so %d: ", i + 1);
        scanf("%d", &myArr[i]);
    }

    int highestNum = myArr[0];
    for (int i = 1; i < n; i++) {
        if (myArr[i] > highestNum)
            highestNum = myArr[i];
    }

    printf("Max: %d\n", highestNum);

    free(myArr);
    myArr = NULL;
    return 0;
}
