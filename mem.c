#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1024 * 1024

int main (void) {

    char *p = NULL;
    char *input = malloc(1024 * 1024);
    while (fgets(input, MAXLINE, stdin) != NULL) {
        int num = atoi(input);
        p = malloc(1024 * 1024 * num);
        if (p != NULL) {
            printf("Malloced %d megs\n", num);
            for (int i = 0; i < 1024 * 1024 * num; i++) {
                p[i] = 69;
            }
        }
        else 
            printf("Malloc failed!\n");
    }
    free(p);
    free(input);

    return 0;
}
