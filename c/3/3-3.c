#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[]) {
    char c;
    for (int i = 0, j = 0; i < strlen(s1); i++, j++) {
        c = s1[i];
        if (s1[i+1] == '-') {
        }
        putchar(c);
    }
}

int main() {
    char s1[] = "Write a function expand(s1,s2) that expands shorthand"
        "notations like a-z in the string s1 into the equivalent complete list"
        "abc...xyz in s2. Allow for letters of either case and digits, and be"
        "prepared to handle cases like a-b-c and a-z0−9 and -a-z. Arrange that"
        "a leading or trailing - is taken literally-.";
    char s2[0];
    expand(s1, s2);
    printf("s1 = %s\n", s1);
}
