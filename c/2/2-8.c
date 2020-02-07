#include <stdio.h>
#include "printbits.h"

unsigned rightrot(unsigned int x, unsigned int n) {
    int shifted = x >> n;
    printf("shifted\n");
    qpb(shifted);
    return x;
}

int main() {
    unsigned int x = 0b10101010101010101010101010101010;
    unsigned int n = 5;
    printf("n = %i\n", n);
    printf("X\n");
    qpb(x);
    unsigned result = rightrot(x, n);
    printf("result\n");
    qpb(result);
}
