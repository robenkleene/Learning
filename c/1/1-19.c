#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
int reverse(char s[]);

int main() {
    char line[MAXLINE];

    while ((get_line(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}

int reverse(char s[]) {
    char reversed[MAXLINE];
    int i, j, len;
    // j = strlen(s) - 2, the 2 is to skip the trailing new line
    len = strlen(s);
    for (i = 0, j = len - 2; i < strlen(s) && j >= 0; i++, j--) {
        reversed[i] = s[j];
    }
    reversed[i] = '\n';
    i++;
    reversed[i] = '\0';
    strncpy(s, reversed, MAXLINE);
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
