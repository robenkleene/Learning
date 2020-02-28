#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[]) {
    char c;
    for (int i = 0, j = strlen(s1) - 1; i < j; i++, j--)
        c = s1[i], s1[i] = s1[j], s1[j] = c;
}

int main() {
    char s1[] = "hello, world";
    char s2[0];
    expand(s1, s2);
    printf("s1 = %s\n", s1);
}
