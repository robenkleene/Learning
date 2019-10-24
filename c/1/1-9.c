#include <stdio.h>

#define IN 1  /* Inside a space */
#define OUT 0 /* Not inside a space */

int main() {
    int c, state;
    while ((c = getchar()) != EOF)
        if (c == ' ' ) {
            if (state != IN) {
                state = IN;
                putchar(c);
            }
        } else {
            state = OUT;
            putchar(c);
        }
}
