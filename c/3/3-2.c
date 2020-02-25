#include <stdio.h>

#define MAXLENGTH 1000

static void escape(char s[], char t[]) {
    int i = 0, j = 0;
    char c;
    while ((c = s[i]) != '\0') {
        switch (c) {
            case '\n':
                t[j] = '\\';
                j++;
                t[j] = 'n';
                break;
            case '\t':
                t[j] = '\\';
                j++;
                t[j] = 't';
                break;
            default:
                t[j] = c;
                break;
        }
        ++i;
        ++j;
    }
}

int main() {
    char start[] = "A string with a \t and a \n";
    char result[MAXLENGTH];
    printf("Initial\n%s\n", start);
    escape(start, result);
    printf("Escaped\n%s\n", result);
}
