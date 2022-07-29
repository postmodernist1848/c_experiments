#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define sectomicrosec(sec) (int) (sec * 1000000)
bool isnumber(char *str) {
    while(isdigit(*str)) str++;
    if (*str == '\0')
        return true;
    else
        return false;
}

void print_last_n(char *str, int n) {
    str += strlen(str) - n;
    printf("%s", str);
}

void print_first_n(char *str, int n) {
    printf("%.*s", n, str);
}

int main (int argc, char *argv[]) {

    double duration = -1;
    time_t begin;
    time(&begin);
    time_t cur_time;

    if (argc > 1)
        if (isnumber(argv[1])) {
            duration = atof(argv[1]);
        }

    char *line = "НИГЕР ПИДОР НИГЕР ПИДОР НИГЕР ПИДОР НИГЕР ПИДОР НИГЕР ПИДОР НИГЕР ПИДОР НИГЕР ПИДОР НИГЕР ПИДОР НИГЕР ПИДОР ";
    int len = strlen(line);

    int first = len;
    int last = 0;
    while (duration == -1 || difftime(cur_time, begin) < duration) {
        putchar('\r');
        print_last_n(line, last);
        print_first_n(line, first);
        fflush(stdout);
        int d = isspace(line[len - last]) ? 1: 2;
        first = (first + d) % len;
        last = len - first;
        usleep(sectomicrosec(0.1));
        time(&cur_time);
    }
    putchar('\n');


    return 0;
}
