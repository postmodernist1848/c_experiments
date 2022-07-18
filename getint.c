/* get an int from stdin. Similar to atoi. */
#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);

int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1: 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            ungetch(44 - sign); //43 is '+' and 45 is '-' so (44 - sign) gets the needed sign character
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int main (void) {

    int c, n;

    getint(&n);
    printf("%d\n", n);
    printf("Leftover:\n");
    while ((c = getch()) != EOF)
        putchar(c);

    return 0;
}

#define BUFFSIZE 100

char buf[BUFFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFFSIZE)
        printf("ungetch: too many characters in buffer\n");
    else buf[bufp++] = c;
}
