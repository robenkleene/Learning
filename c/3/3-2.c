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

static void unescape(char s[], char t[]) {
    int i = 0, j = 0;
    char c;
    while ((c = s[i]) != '\0') {
        if (c == '\\') {
            i++;
            switch (s[i]) {
                case 'n':
                    t[j] = '\n';
                    break;
                case 't':
                    t[j] = '\t';
                    break;
                default:
                    i--;
                    t[j] = c;
                    break;
            }
        } else {
            t[j] = c;
        }
        ++i;
        ++j;
    }
}

int main() {
    char start[] = "A string with\\ a \t and a \n";
    printf("Initial\n%s\n", start);
    char escaped[MAXLENGTH];
    escape(start, escaped);
    printf("Escaped\n%s\n", escaped);
    char unescaped[MAXLENGTH];
    unescape(escaped, unescaped);
    printf("Unescaped\n%s\n", unescaped);
}
