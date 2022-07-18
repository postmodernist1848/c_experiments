/* print first line that is different in two files given as command line arguments or none if there is no diference */
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int main (int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "%s: wrong number of arguments\n", argv[0]);
        return 1;
    }
    FILE *f1 = fopen(argv[1], "r");
    if (f1 == NULL) {
        fprintf(stderr, "%s: unable to open file '%s'\n", argv[0], argv[1]);
        return 1;
    }
        
    FILE *f2 = fopen(argv[2], "r");
    if (f1 == NULL) {
        fprintf(stderr, "%s: unable to open file '%s'\n", argv[0], argv[2]);
        return 1;
    }

    char line1[MAXLINE], line2[MAXLINE];
    while (fgets(line1, MAXLINE, f1) != NULL && fgets(line2, MAXLINE, f2) != NULL) {
        if (strcmp(line1, line2) != 0) {
            printf("Diff:\n%s\n%s\n", line1, line2);
            return 0;
        }
    }

    return 0;
}
