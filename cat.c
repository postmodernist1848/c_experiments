/* cat implementation using read and write syscalls 
 * (proved to be 2 times more efficient than the version that used FILE pointers and getc)
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>

void error(char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "Error: ");
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    va_end(ap);
    exit(1);
}

int main (int argc, char *argv[]) {
    char *buf[BUFSIZ];
    int n;
    if (argc == 1) {
        while ((n = read(0, buf, BUFSIZ)) > 0) {
            write(1, buf, n);
        }
    }
    else {
        int fd;
        while (--argc) {
            if ((fd = open(*++argv, O_RDONLY)) == -1) {
                error("couldn't open %s", *argv);
            }
            while ((n = read(fd, buf, BUFSIZ)) > 0) {
                if (write(1, buf, n) != n)
                    error("error writing to stdout");
            }
        }
    }

    return 0;
}
