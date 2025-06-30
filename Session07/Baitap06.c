#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le.\n");
        return 1;
    }

    int arr[n], am[n], khong[n], duong[n];
    int demAm = 0, dem0 = 0, demDuong = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] < 0) am[demAm++] = arr[i];
        else if (arr[i] == 0) khong[dem0++] = arr[i];
        else duong[demDuong++] = arr[i];
    }

    printf("before: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    int idx = 0;
    for (int i = 0; i < demAm; i++) arr[idx++] = am[i];
    for (int i = 0; i < dem0; i++) arr[idx++] = khong[i];
    for (int i = 0; i < demDuong; i++) arr[idx++] = duong[i];

    printf("after: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}