#include <stdio.h>
#include "printbits.h"

unsigned rightrot(x, n) {
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
