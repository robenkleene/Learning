#include <stdio.h>

#define IN 1
#define OUT 0
#define LENGTH 30

int main() {
    int c, nc, state;
    int wcount[LENGTH] = {0};
    state = OUT;
    nc = 0;
    do {
        c = getchar();
        if (state == IN)
            ++nc;
        if (c == ' ' || c == '\n' || c == '\t' || c == EOF) {
            if (nc > 0) {
                if (nc < LENGTH) {
                    wcount[nc]++;
                } else {
                    printf("%d is too many characters.\n", nc);
                }
            }
            nc = 0;
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            nc = 1;
        }
    } while (c != EOF);
    for (int i = 0; i < LENGTH; i++) {
        int cc = wcount[i];
        if (cc > 0) {
            printf("%2d ", i);
            for (int j = 0; j < cc; j++) {
                putchar('-');
            }
            putchar('\n');
        }
    }
}
