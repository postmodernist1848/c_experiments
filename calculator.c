#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define tracing 0

int getop(char[]);
void push(double);
double pop(void);
void clear(void);

enum { WRITE, READ, SIN, EXP, POW };

int main(void) {
    printf("    REVERSE POLISH CALCULATOR\n>> ");
    int type, print=0;
    double op2, op1, last;
    char s[MAXOP];
    double vars[27] = {0};
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int) pop() % (int) op2);
                else
                    printf("error: zero divisor");
                break;
            case 'p':
                print = 1;
                break;
            case 'd':
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 's':
                op2 = pop();
                op1 = pop();
                push(op2);
                push(op1);
                break;
            case 'c':
                clear();
                break;
            case SIN:
                push(sin(pop()));
                break;
            case EXP:
                push(exp(pop()));
                break;
            case POW:
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case WRITE:
                if (strlen(s) != 2) printf("error: only single-letter names for variables are allowed.\nName given: %s\n", s);
                else
                if ('a' <= s[1] && s[1] <= 'z')
                    vars[s[1] - 'a'] = pop();
                break;
            case READ:
                if (strlen(s) != 2) printf("error: only single-letter names for variables are allowed.\nName given: %s\n", s);
                else
                if ('a' <= s[1] && s[1] <= 'z')
                    push(vars[s[1] - 'a']);
                else if (s[1] == '?')
                    push(last);
                else printf("error: unknown variable name %c\n", s[1]);
                break;
            case '\n':
                if (print) {
                    op2 = pop();
                    printf("\t%.8g\n>> ", op2);
                    last = op2;
                    push(op2);
                    print = 0;
                }
                else {
                    last = pop();
                    printf("\t%.8g\n>> ", last);
                }
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    puts("\nExiting...");
    return 0;
}

#define MAXVAL 100
int sp=0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL) { 
        val[sp++] = f;
        if (tracing) printf("pushed %lf\n", f);
    }
    else printf("error: stack fill, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0) {
        return val[--sp];
        if (tracing) printf("popped %lf\n", val[sp]);
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void clear(void) {
    sp = 0;
}
    
#include <ctype.h>
int getch(void);
void ungetch(int);

int getop(char s[]) {
    int i=0, c; 

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    if (c == '\n' || c == EOF) return c;

    while (!isspace(c) && c != EOF) {
        s[i++] = c;
        c = getch();
    }
    s[i] = '\0';
    //check what happens if it's EOF
    if (c != EOF) ungetch(c);
    if (s[0] == '@') return WRITE;
    else if (s[0] == '$') return READ;
    else if (strcmp(s, "sin") == 0) return SIN;
    else if (strcmp(s, "exp") == 0) return EXP;
    else if (strcmp(s, "pow") == 0) return POW;


    if (!isdigit(s[0]) && s[0] != '.' && !isdigit(s[1])) {
        return s[0];
    }
    //maybe add safety checks here
    return NUMBER;
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


