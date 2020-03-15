#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

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

/* Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s. In particular, itob(n,s,16) formats n as a hexadecimal integer in s. */
void itob(int n, char s[], int b) {
    int i, sign;
    sign = n;

    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while (n /= 10);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    strrev(s);
}

int main() {
    char s[LENGTH];

    int i = 10;
    printf("i = %i\n", i);
    printf("ix = %x\n", i);
    /* itob(i, s); */
    /* printf("s = %s\n", s); */
    /* printf("\n\n"); */

    /* i = INT_MIN; */
    /* printf("i = %i\n", i); */
    /* itob(i, s); */
    /* printf("s = %s\n", s); */
    /* printf("\n\n"); */

    /* i = INT_MIN + 1; */
    /* printf("i = %i\n", i); */
    /* itoa(i, s); */
    /* printf("s = %s\n", s); */
}
