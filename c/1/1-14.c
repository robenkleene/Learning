#include <stdio.h>
#include <ctype.h>

#define LENGTH 128

int main() {
    int c;
    int ccount[LENGTH] = {0};
    while ((c = getchar()) != EOF) {
        if (isprint(c)) {
            ccount[c]++;
        }
    }
    for (int i = 0; i < LENGTH; i++) {
        int cc = ccount[i];
        if (cc > 0) {
            putchar(i);
            putchar(' ');
            for (int j = 0; j < cc; j++) {
                putchar('-');
            }
            putchar('\n');
        }
    }
}
