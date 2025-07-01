#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main() {
    int n;
    int arr[1000];

    do {
        printf("Nhap so luong phan tu (0 < n < 1000): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 1000);

    printf("Nhap %d phan tu cua mang:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int search;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &search);

    int result = linearSearch(arr, n, search);

    if (result == -1) {
        printf("Khong ton tai phan tu\n");
    } else {
        printf("Vi tri thu %d\n", result + 1);
    }

    return 0;
}
