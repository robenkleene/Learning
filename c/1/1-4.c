#include <stdio.h>

#define LOWER -20   /* lower limit of table */
#define UPPER 150 /* upper limit */
#define STEP 10   /* step size */

/* print Fahrenheit-Celsius table */
int main() {
    int cel;

    for (cel = LOWER; cel <= UPPER; cel = cel + STEP)
        printf("%3d %6.1f\n", cel, cel * (9.0 / 5.0) + 32);
}
