/* A fun play on argv[0] - if the name of the program is upper, it converts the input to uppercase,
 * otherwise, it converts it to lowercase
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int c, i;
    for (i = strlen(argv[0]) - 1; i >= 0 && argv[0][i] != '/'; i--);
    printf("%s\n", argv[0] + i + 1);
    if (strcmp(argv[0] + i + 1, "upper") == 0) {
        while ((c = getchar()) != EOF)
            putchar(toupper(c));
    }
    else {
        while ((c = getchar()) != EOF)
            putchar(tolower(c));
    }

    return 0;
}
