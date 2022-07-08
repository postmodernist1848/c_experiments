#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 1000
#define MAXLINE 1000
#define LINES_STORAGE 10000
#define N 10;

int readline(char line[], int max) {
    int c, i = 0;
    while (i + 1 < max && (c = getchar()) != EOF && c != '\n')
        line[i++] = c;
    if (c == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return i;
};

/* tail: print n last lines of input */
int main (int argc, char *argv[]) {
    int n;

    if (argc > 2) { printf("Usage: tail [-n]\n"); return 1; }
    else if (argc == 2) {
        if (argv[1][0] == '-')
            n = atoi(++argv[1]);
        else {
            printf("Usage: tail [-n]\n"); return 1;
        }
    }
    else
        n = N;

    
    char lines[LINES_STORAGE];
    char *lineptr[MAXLINES];

    //read into linesptr
    char line[MAXLINE];
    char *p;
    int len, sp=0, nlines=0;

    while ((len = readline(line, MAXLINE)) > 0) {
        if (nlines >= MAXLINES || (sp + len) > LINES_STORAGE) {
            //overwhelmed limits
            printf("Warning: internal limit reached\n");
            break;
        }
        else {
            p = lines + sp;
            strcpy(p, line);
            lineptr[nlines++] = p;
            sp += len + 1;
        }
    }

    //print last n lines
    for (int i = (nlines > n) ? nlines - n: 0; i < nlines; i++)
        printf("%s", lineptr[i]);

    return 0;
}
