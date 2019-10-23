#include <stdio.h>

int main() {
    int c, nb, nt, nl;

    nb = nt = nl = 0;
    while ((c = getchar()) != EOF) {
        switch (c) {
            case ' ':
                ++nb;
                break;
            case '\n':
                ++nl;
                break;
            case '\t':
                ++nt;
                break;
            default:
                break;
        }
    }
    printf("%d %d %d\n", nb, nl, nt);
}
