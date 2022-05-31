#include <stdio.h>

int main(void) {
    int c, blanks=0;
    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\n' || c == '\t')
            blanks++;
    printf("\n%d\n", blanks);
return 0;
}