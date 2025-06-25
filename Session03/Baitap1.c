#include <stdio.h>
#include <stdlib.h>

int main() {
   int n;
   do {
      printf("Nhap so nguyen n: ");
      scanf("%d", &n);
   }while (n <= 0 || n >= 1000);

   int *myArray = malloc(n * sizeof(int));

   for (int i = 0; i < n; i++) {
      do {
         printf("Nhap phan tu so %d: ", i + 1);
         scanf("%d", &myArray[i]);
         if (myArray[i] == 0) {
            printf("So phan tu so %d khong duoc am\n", i + 1);
         }else if (myArray[i] < 0) {
            printf("So luong phan tu phai lon hon 0");
         }
      }while (myArray[i] < 1 || myArray[i] > 1000);
   }
   for (int i = 0; i < n; i++) {
         printf("so thu %d la: %d\n",1+i,  myArray[i]);
   }
   free(myArray);
   myArray = NULL;
   return 0;
}