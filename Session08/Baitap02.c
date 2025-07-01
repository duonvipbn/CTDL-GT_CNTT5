#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
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

    printf("Nhap %d phan tu da sap xep tang dan:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int search;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &search);

    int result = binarySearch(arr, n, search);

    if (result == -1) {
        printf("Khong ton tai phan tu\n");
    } else {
        printf("Phan tu vi tri thu %d\n", result + 1);
    }

    return 0;
}
