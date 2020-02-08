#include <stdio.h>
#include "printbits.h"

int rightrot(x, n) {
    unsigned int ux = x;
    int shifted = ux >> n;
    printf("shifted\n");
    qpb(shifted);
    return x;
}

int main() {
    int x = 0b10101010101010101010101010101010;
    int n = 5;
    printf("n = %i\n", n);
    printf("X\n");
    qpb(x);
    unsigned result = rightrot(x, n);
    printf("result\n");
    qpb(result);
}
