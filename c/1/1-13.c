#include <stdio.h>

#define IN 1
#define OUT 0
#define LENGTH 30

int main() {
    int c, nc, state;
    int wcount[LENGTH] = {0};
    state = OUT;
    nc = 0;
    while ((c = getchar()) != EOF) {
        if (state == IN)
            ++nc;
        if (c == ' ' || c == '\n' || c == '\t') {
            wcount[nc]++;
            nc = 0;
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            nc = 1;
        }
    }
    for (int i = 0; i < LENGTH; i++) {
        int cc = wcount[i];
        if (cc > 0)
            printf("%d %d\n", i, cc);
    }
}
