#include <stdio.h>

int deQuy(int firstNum, int secondNum) {
    if (firstNum == secondNum) return firstNum;
    return firstNum + deQuy(firstNum + 1, secondNum);
}

int main() {
    int firstNum, secondNum, c;

    do {
        printf("Nhap mot so nguyen duong 1 (nho hon so 2): ");
        if (scanf("%d", &firstNum) != 1 || firstNum < 1) {
            printf("So khong hop le! Moi nhap lai.\n");
            while ((c = getchar()) != EOF && c != '\n');
        } else {
            break;
        }
    } while (1);

    do {
        printf("Nhap mot so nguyen duong 2 (lon hon so 1): ");
        if (scanf("%d", &secondNum) != 1 || secondNum < 1) {
            printf("So khong hop le! Moi nhap lai.\n");
            while ((c = getchar()) != EOF && c != '\n');
        } else if (secondNum <= firstNum) {
            printf("So thu hai phai lon hon so thu nhat! Moi nhap lai.\n");
            while ((c = getchar()) != EOF && c != '\n');
        } else {
            break;
        }
    } while (1);

    int total = deQuy(firstNum, secondNum);
    printf("Tong tu %d den %d la: %d\n", firstNum, secondNum, total);

    return 0;
}
