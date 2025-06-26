#include <stdio.h>

int giaiThua(int n) {
    if (n == 1) {
        return 1;
    }
    return n * giaiThua(n - 1);
}

int main(){
    int n, c;
    do {
        printf("Nhap mot so nguyen duong bat ky:");
        if (scanf("%d", &n) != 1 ||  n < 1) {
            printf("So khong hop le! Moi nhap lai.\n");
            while ((c = getchar()) != EOF && c != '\n');
        }else {
            break;
        }
    }while (1);

    int total = giaiThua(n);
    printf("Tong giai thua: %d", total);

    return 0;
}
