#include <stdio.h>
#include <stdlib.h>


int recursion(int num) {
    if (num == 0) {
        return 0;
    }

    recursion(num / 2);
    printf("%d", num % 2);
}

// 10   :    2    5    0
// 5    :    2    2    1
// 2    :    2    1    0
// 1    :    2    0.5  1

int main() {
    int n, c;

    do {
        printf("nhap so nguyen duong bat ky:");
        if (scanf("%d", &n) != 1 || n < 1) {
            printf("So khong hop le! phai la so nguyen duong.");
            while ((c = getchar()) != '\n' &&  c != EOF);
        }else {
            break;
        }
    }while (1);

    recursion(n);

    return 0;
}
