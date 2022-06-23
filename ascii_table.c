#include <stdio.h>

#define ROWS 15
int main (void) {
    for (int i; i < ROWS; i++) {
        for (int j=0; j < 7; j++) {
            char c = '!' + j * ROWS + i;
            if (c >= 127 || c < 0) break;
            if (93 <= c && c <= 99)
            printf("%d: %c     ", c, c);
            else
            printf("%d: %c    ", c, c);
    }
    putchar('\n');
    }
    return 0;
}

