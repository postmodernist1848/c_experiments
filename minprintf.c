/* an excersize in variadic functions - a minimal version of printf and scanf
 * that uses scanf and printf internally */

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

void minprintf(char *fmt, ...) {
    va_list ap;
    char *p, *sval, cval;
    int ival;
    double dval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            case 'c':
                cval = va_arg(ap, int);
                putchar(cval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}

void minscanf(char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    for (char *p = fmt; *p; p++) {
        if (isspace(*p)) continue;
        if (*p != '%') {
            if (getchar() != *p) {
                break;
            }
        }
        switch (*++p) {
            case 'd':
                scanf("%d", va_arg(ap, int *));
                break;
            case 'f':
                scanf("%f", va_arg(ap, float *));
                break;
            case 's':
                scanf("%s", va_arg(ap, char *));
                break;
            case 'c':
                scanf("%c", va_arg(ap, char *));
                break;
        }
    }
    va_end(ap);
}

int main (void) {
    char s[100];
    int d;
    float f;

    minscanf("%s %d %f", s, &d, &f);

    minprintf("Here are printable chars and a string: %s, int: %d, float: %f\n", s, d, f);
    
    return 0;
}
