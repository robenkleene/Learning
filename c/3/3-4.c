#include <stdio.h>
#include <string.h>
#include <limits.h>

#define LENGTH 1000

char *strrev(char *str) {
    char *p1, *p2;

    if (!str || !*str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

// The original implementation fails if `n == INT_MIN` because in two's
// complement negative numbers can have one higher in absolute value, because
// positive integers lose one value by representing zero.
void itoa(int n, char s[]) {
    int i, sign;
    if ((sign = n) < 0)
        n = -n;
    printf("n = %i\n", n);
    i = 0;
    do {
        printf("n mod 10 = %i\n", n % 10);
        s[i++] = n % 10 + '0';

        printf("i = %i\n", i);
        printf("s[i - 1] = %i\n", s[i - 1]);
        printf("s[i - 1] = %c\n", s[i - 1]);
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    strrev(s);
}

int main() {
    char s[LENGTH];

    int i = INT_MIN;
    printf("i = %i\n", i);
    itoa(i, s);
    printf("s = %s\n", s);
    printf("\n\n");

    i = INT_MIN + 1;
    printf("i = %i\n", i);
    itoa(i, s);
    printf("s = %s\n", s);
}
