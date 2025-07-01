#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

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
    int n, arr[1000];

    printf("Nhap so luong phan tu (0 < n < 1000): ");
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }

    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Mang ban dau:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    insertionSort(arr, n);

    printf("Mang sau khi sap xep:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    int x;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    int linearResult = linearSearch(arr, n, x);
    int binaryResult = binarySearch(arr, n, x);

    if (linearResult != -1)
        printf("Tim thay (tuyen tinh) tai vi tri thu %d\n", linearResult + 1);
    else
        printf("Khong tim thay (tuyen tinh)\n");

    if (binaryResult != -1)
        printf("Tim thay (nhi phan) tai vi tri thu %d\n", binaryResult + 1);
    else
        printf("Khong tim thay (nhi phan)\n");

    return 0;
}
