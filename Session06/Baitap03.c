
int recursion(int n) {
    if (n == 0) return 0;
    return n % 10 + recursion(n / 10);
}

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

   printf("Tong: %d", recursion(n));

    return 0;
}