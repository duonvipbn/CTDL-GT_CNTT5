#include <stdio.h>

void deQuy(int n){
    if(n == 1){
        printf("1\n");
        return;
    }
    deQuy(n - 1);
    printf("%d\n", n);
}

int main(){
    int n, c;
    do{
        printf("Nhap mot so N nguyen duong bat ky:");
        if(scanf("%d",&n) != 1 || n < 1){
            printf("N khong hop le! Vui long nhap lai.\n");
            while ((c = getchar()) != '\n' && c != EOF);
        }else {
            break;
        }
    }while(1);

    deQuy(n);
    return 0;
}
