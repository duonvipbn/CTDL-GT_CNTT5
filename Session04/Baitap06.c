#include <stdio.h>
#include <string.h>

#define SIZE 5
#define NAME_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    int age;
} Student;

int main() {
    Student students[SIZE];
    int search_id;
    int found = 0;
    int c;

    for (int i = 0; i < SIZE; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);

        printf("ID: ");
        while (scanf("%d", &students[i].id) != 1) {
            printf("ID khong hop le! Nhap lai: ");
            while ((c = getchar()) != EOF && c != '\n');
        }
        while ((c = getchar()) != EOF && c != '\n');

        printf("Ten: ");
        fgets(students[i].name, NAME_LEN, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("Tuoi: ");
        while (scanf("%d", &students[i].age) != 1) {
            printf("Tuoi khong hop le! Nhap lai: ");
            while ((c = getchar()) != EOF && c != '\n');
        }
        while ((c = getchar()) != EOF && c != '\n');
    }

    printf("\nNhap ID sinh vien can tim: ");
    while (scanf("%d", &search_id) != 1) {
        printf("ID khong hop le! Nhap lai: ");
        while ((c = getchar()) != EOF && c != '\n');
    }
    while ((c = getchar()) != EOF && c != '\n');

    for (int i = 0; i < SIZE; i++) {
        if (students[i].id == search_id) {
            printf("\n{ id: %d, name: \"%s\", age: %d }\n", students[i].id, students[i].name, students[i].age);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nSinh vien khong ton tai\n");
    }

    return 0;
}
