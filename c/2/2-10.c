#include <stdio.h>

int lower(int c) {
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

int main() {
    int result = lower('B');
    printf("result = %c\n", result);
}
