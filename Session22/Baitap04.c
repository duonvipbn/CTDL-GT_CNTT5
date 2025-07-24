#include <stdio.h>

#define MAX 100

int main() {
    int n;
    int matrix[MAX][MAX];
    int count = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] == 1) {
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}
