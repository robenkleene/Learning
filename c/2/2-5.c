#include <stdio.h>

int any(char s1[], char s2[]) {
    int i, j, k;

    for (i = 0; s1[i] != '\0'; i++) {
        for (k = i; s1[k] != '\0'; k++) {
            for (j = 0; s2[j] != '\0'; j++) {
                if (s1[k] != s2[j])
                    break;
                return i;
            }
            break;
        }
    }

    return -1;
}

int main() {
    char s[] = "hello, world\n";
    int r = any(s, "world");
    printf("%i\n", r);
    r = any(s, "nothing");
    printf("%i\n", r);
}
