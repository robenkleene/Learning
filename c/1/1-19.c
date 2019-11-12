#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_line(char s[], int lim);

int main() {
    char line[MAXLINE];

    while ((get_line(line, MAXLINE)) > 0) {
    }
    return 0;
}

int reverse(char s[]) {
    char reversed[MAXLINE];
    int i, j;
    for (i = 0, j = strlen(s) - 1; i < strlen(s) && j >= 0; i++, j--) {
        reversed[i] = s[j];
    }
    return 0;
}

int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1) {
            s[i] = c;
        }
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
