#include <stdio.h>

void squeeze(char s1[], char s2[]) {
    int i, j;

    for (i = j = 0; s1[i] != '\0'; i++)
        if (s1[i] != s2[0])
            s1[j++] = s1[i];
    s1[j] = '\0';
}

int main() {
    char s[] = "hello, world\n";
    squeeze(s, "l");
    printf("%s", s);
}
