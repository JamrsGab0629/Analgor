#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char getRandomChar() {
    int r = rand() % 62;
    if (r < 10) return '0' + r;
    else if (r < 36) return 'A' + (r - 10);
    else return 'a' + (r - 36);
}

void generateRandomString(char *str, int n) {
    for (int i = 0; i < n; i++) {
        str[i] = getRandomChar();
    }
    str[n] = '\0';
}

int main() {
    int n;
    printf("Enter string length: ");
    scanf("%d", &n);

    srand(time(NULL));
    char *str = malloc(n + 1);
    generateRandomString(str, n);
    printf("Random String: %s\n", str);
    free(str);
    return 0;
}
