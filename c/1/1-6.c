#include <stdio.h>

int main() {
    int r;

    do {
        r = getchar() == EOF;
        switch (r) {
            case 0:
            case 1:
                printf("%i", r);
                break;
            default:
                printf("\nThe result wasn\'t 0 or 1!");
                break;
        }
    } while (r != 1);
}
