#include <stdio.h>

void tower(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Dia 1 di chuyen tu %c sang %c\n", from, to);
        return;
    }
    tower(n - 1, from, aux, to);
    printf("Dia %d di chuyen tu %c sang %c\n", n, from, to);
    tower(n - 1, aux, to, from);
}

int main() {
    int n, c;
    do {
        printf("Nhap so dia: ");
        if (scanf("%d", &n) != 1 || n < 1) {
            printf("Input khong hop le\n");
            while ((c = getchar()) != '\n' && c != EOF);
            return 1;
        } else {
            break;
        }
    } while (1);

    tower(n, 'A', 'C', 'B');
    return 0;
}
