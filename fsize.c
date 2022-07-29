#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024

size_t g_total;
int print_only_total;

void print_human_size(size_t size, char *name) {
    char quantity='B';
    double formated_size = size;
    if (formated_size > 1024) {
        formated_size /= 1024;
        quantity = 'K';
    }
    if (formated_size > 1024) {
        formated_size /= 1024;
        quantity = 'M';
    }
    if (formated_size > 1024) {
        formated_size /= 1024;
        quantity = 'G';
    }

    if (quantity == 'B')
        printf("%8.lf %s\n", formated_size, name);
    else
        printf("%8.1lf%c %s\n", formated_size, quantity, name);
}

void dirwalk(char *dir, void (*fcn)(char *)) {
    char name[MAX_PATH];
    struct dirent *dp;
    DIR *dfd;

    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }
    while ((dp = readdir(dfd)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 ||
            strcmp(dp->d_name, "..") == 0)
            continue;
        if (strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name))
            fprintf(stderr, "dirwalk: name %s/%s/ too long\n", dir, dp->d_name);
        else {
            sprintf(name, "%s/%s", dir, dp->d_name);
            (*fcn)(name);
        }
    }
    closedir(dfd);
}

void fsize(char *name) {
    struct stat stbuf;
    size_t len = strlen(name);
    if (name[len - 1] == '/')
        name[len - 1] = '\0';

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);

    g_total += stbuf.st_size;
    if (!print_only_total)
        print_human_size(stbuf.st_size, name);
}


int main (int argc, char *argv[]) {
    int met_path = 0;

    while (--argc) {
        if ((*++argv)[0] == '-') {
            if (strcmp(*argv, "-t") == 0) {
                print_only_total = 1;
            }
            else {
                fprintf(stderr, "unknown argument '%s'", *argv);
                return 1;
            }
        }
        else {
            fsize(*argv);
            met_path = 1;
        }
    }

    if (!met_path)
        fsize(".");

    print_human_size(g_total, "total");

    return 0;
}
