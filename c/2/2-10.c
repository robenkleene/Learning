#include <stdio.h>

int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

int main() {
    int result = lower('B');
    printf("result = %c\n", result);
}
