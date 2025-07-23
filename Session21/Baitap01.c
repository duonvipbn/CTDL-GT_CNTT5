#include <stdio.h>

#define SIZE 3

void initArr(int array[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            array[i][j] = 0;
        }
    }
}

void printArr(int array[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}
void addEdge(int array[SIZE][SIZE], int pF, int pS) {
    array[pF-1][pS-1] = 1;
    array[pS-1][pF-1] = 1;
}

int main() {
    int array[SIZE][SIZE];
    initArr(array);
    int pF = 1, pS = 2;

    addEdge(array, pF, pS);
    printArr(array);
    return 0;
}