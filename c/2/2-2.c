#include <stdio.h>

#define MAXLINE 1000

int main() {
    int lim = MAXLINE;
    char s[MAXLINE];
    for (int i = 0; i < lim - 1; ++i) {
        int c = getchar();
        if (c == '\n') {
            break;
        }
        if (c == EOF) {
            break;
        }
        s[i] = c;
    }
    printf("%s", s);
}


