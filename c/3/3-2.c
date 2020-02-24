#include <stdio.h>

static void escape(char s[], char t[]) {
    int i = 0;
    char c;
    while ((c = s[i]) != '\0') {
        switch (c) {
            case '\n':
            case '\t':
                t[i] = c;
                break;
            default:
                t[i] = c;
                break;
        }
        ++i;
    }
}

int main() {
    char start[] = "A string with a \t and a \n";
    size_t size = sizeof(start) / sizeof(char);
    char result[size];
    printf("start = %s\n", start);
    escape(start, result);
    printf("result = %s\n", result);
}
