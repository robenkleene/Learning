#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
#define THRESHOLD 80

int get_line(char s[], int lim);

/* print longest input line */
int main() {
    int len;               /* current line length */
    int max;               /* maximum length seen so far */
    char line[MAXLINE];    /* current input line */

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len >= MAXLINE)
            fprintf(stderr, "Printing the first %d characters because the longest line was %d which is longer than the maxium length of %d\n", MAXLINE - 1, max, MAXLINE - 1);
        if (len >= 80) /* there was a line */
            printf("%s", line);
    return 0;
}

/* get_line:  read a line into s, return length */
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
