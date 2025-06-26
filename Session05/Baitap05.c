#include <stdio.h>
#include <string.h>

char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z') return c + 32;
    return c;
}

int isAlphaNum(char c) {
    return (c >= 'A' && c <= 'Z') ||
           (c >= 'a' && c <= 'z') ||
           (c >= '0' && c <= '9');
}

void cleanString(char *src, char *dest) {
    int j = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        if (isAlphaNum(src[i])) {
            dest[j++] = toLowerCase(src[i]);
        }
    }
    dest[j] = '\0';
}

int isPalindrome(char *str, int left, int right) {
    if (left >= right) return 1;
    if (str[left] != str[right]) return 0;
    return isPalindrome(str, left + 1, right - 1);
}

int main() {
    char input[1000];
    char cleaned[1000];

    printf("Nhap chuoi bat ky: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    cleanString(input, cleaned);

    if (isPalindrome(cleaned, 0, strlen(cleaned) - 1)) {
        printf("Chuoi doi xung (Palindrome valid)\n");
    } else {
        printf("Khong phai chuoi doi xung (Not palindrome)\n");
    }

    return 0;
}
