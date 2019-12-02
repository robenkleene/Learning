#include <stdio.h>

#define MAXLINE 1000

int main() {
    int lim = MAXLINE;
    char s[MAXLINE];
    for (int i = 0, c = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;
    printf("%s", s);
}


