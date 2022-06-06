#include <stdio.h>

int main(void) {
    char c = getchar();
    while ((c = getchar()) != EOF)
    putchar(c);
}
