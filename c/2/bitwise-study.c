#include <stdio.h>
#include "printbits.h"

int main() {
    int x = 0b01010101010101010101010101010101;
    int y = 0b10101010101010101010101010101010;
    int result;
    /* printf("X\n"); */
    /* qpb(x); */
    /* printf("Y\n"); */
    /* qpb(y); */

    x = 3;
    y = 5;
    printf("X\n");
    qpb(x);
    printf("Y\n");
    qpb(y);
    result = x & y;
    printf("x & y = %i\n", result);
    qpb(result);
    result = x | y;
    printf("x | y = %i\n", result);
    qpb(result);
    result = x ^ y;
    printf("x ^ y = %i\n", result);
    qpb(result);
}
