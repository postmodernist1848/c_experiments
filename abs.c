/* can someone tell me why this is not a thing? */
#include <stdio.h>

int abs(int x) {
    return (unsigned) x;
}

int main (void) {
    for (int i = -10; i < 10; i++) {
        printf("abs(%d) = %d\n", i, abs(i));
    }

    return 0;
}
