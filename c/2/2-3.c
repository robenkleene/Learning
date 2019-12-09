#include <stdio.h>
#include <stdlib.h>

int htoi(char s[]) {
    return strtol(s, NULL, 16);
}

int main() {
    printf("%i\n", htoi("1A"));
    printf("%i\n", htoi("0X1A"));
    printf("%i\n", htoi("0X1F"));
}
