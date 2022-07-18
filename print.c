/* print input in a sensible way */
#include <stdio.h>

#define MAXLINE 256

int main (void) {
    int line_len = 0, c;
    while ((c = getchar()) != EOF) {
        if (line_len >= MAXLINE || c == '\n') {
            putchar('\n');
            line_len = 0;
            continue;
        }
        if (c >= ' ' && c <= '~' || c == '\n' || c == '\t') {
            putchar(c);
        }
        else {
            printf("[0x%x]", c);
        }
            line_len++;
    }

    return 0;
}
