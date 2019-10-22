#include <stdio.h>

/* count characters in input; 2nd version */
main() {
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        ; // A null statement, because the work is done in the loop.
    printf("%.0f\n", nc);
}
