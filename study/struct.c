#include <stdio.h>

// Define a struct
struct point {
    int x;
    int y;
};

void print_point(struct point pt) {
    printf("%d, %d\n", pt.x, pt.y);
}

int main() {
    // Make a struct variablle
    struct point pt;
    // Initialize a point
    // TODO: Why doesn't this work?
    /* pt = { 5, 10 }; */
    pt.x = 5;
    pt.y = 10;
    print_point(pt);

    // Declare and initialize
    struct point maxpt = { 320, 200 };
    print_point(maxpt);
}
