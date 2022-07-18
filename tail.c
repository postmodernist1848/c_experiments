/* print last n lines of input or from a file. By default n is 10.
 * This can be changed with a commandline argument.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 1000
#define MAXLINE 1000
#define LINES_STORAGE 10000
#define N 10;

int isnumber(char *s) {
    while (*s) {
        if (!isdigit(*s++))
            return 0;
    }
    return 1;
}

int readline(char line[], int max, FILE *fp) {
    int c, i = 0;
    while (i + 1 < max && (c = getc(fp)) != EOF && c != '\n')
        line[i++] = c;
    if (c == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return i;
};

/* tail: print n last lines of input */
int main (int argc, char *argv[]) {
    int n = -1;
    char *filename = NULL;

    while (--argc) {
        if (**++argv == '-') {
            if (isnumber(*argv + 1)) {
                n = atof(*argv + 1);
            }
            else {
                printf("'%s' is not a proper number", *argv + 1); 
                return 1; 
            }
        }
        else
            if (filename == NULL) {
                filename = *argv;
            }
    }
    if (n == -1)
        n = N;

    
    char lines[LINES_STORAGE];
    char *lineptr[MAXLINES];

    //read into linesptr
    char line[MAXLINE];
    char *p;
    int len, sp=0, nlines=0;
    FILE *fp;
    if (filename != NULL) {
        fp = fopen(filename, "r");
    }
    else 
        fp = stdin;
    

    while ((len = readline(line, MAXLINE, fp)) > 0) {
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
    fclose(fp);

    //print last n lines
    for (int i = (nlines > n) ? nlines - n: 0; i < nlines; i++)
        printf("%s", lineptr[i]);

    return 0;
}
