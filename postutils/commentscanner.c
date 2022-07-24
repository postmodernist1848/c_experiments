/* comment scanner - scan files given as arguments or all C files in directory
 * if no arguments are provided for a comment like this one. Used for quick documentation.
 */

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void check(char * filename) {
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Unable to open '%s'\n", filename);
        return;
    }
    char c;
    while (isspace(c = getc(fp)) && c != EOF);
    if (c != '/' || getc(fp) != '*') {
        puts(filename);
    }
}

int main (int argc, char **argv) {
    
    if (argc == 1) {
    struct dirent *de;
    int len;

    DIR *dr = opendir(".");
    while ((de = readdir(dr)) != NULL) {
        len = strlen(de->d_name);
        if (len > 2 && de->d_type == DT_REG && strcmp(de->d_name + len - 2, ".c") == 0)
            check(de->d_name);
    }
    closedir(dr);
    }
    else {
        while(--argc) {
            check(*++argv);
        }
    }

    return 0;
}
