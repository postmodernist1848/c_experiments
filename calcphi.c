#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int main (void) {
    uintmax_t i, j, temp;
    for (i = 0, j = 1; j < UINTMAX_MAX / 2UL; temp = i, i = j, j += temp);

    return 0;
}
