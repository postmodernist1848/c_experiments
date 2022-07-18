/* 
 *
 * Ultimate reverse polish calculator.
 * Use 'help' for help.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Clear command for building on Windows.
#ifdef _WIN32
#define clrscr "cls"
#else
#define clrscr "clear"
#endif

#define MAXLINE 1024
#define MAXWORD 256
#define tracing 0

int read_word(char line[], char word[]);
int get_line(char line[], int max);
int optype(char word[]);
void push(double);
double pop(void);
void clear(void);
int check_stack(void);
void print_help(void);
int execute_word(char word[]);


enum { NUMBER, 
    PLUS, 
    MINUS, 
    MUL, 
    DIV, 
    REM, 
    PRNT, 
    DUP, 
    SWP, 
    CLR, 
    SIN, 
    COS,
    TAN,
    SQRT,
    EXP, 
    POW, 
    WRITE, 
    READ, 
    CLRSCR,
    EXIT,
    UNKWN_CMD,  
    HELP
};

//globals
double last=0; 
int print=0;
int line_pos;

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    char word[MAXWORD];

    if (argc > 1) {
        while (--argc > 0) {
            execute_word(*++argv);
        }
        if (check_stack()) {
            last = pop();
            if (check_stack()) {
                //more than one - print entire stack
                printf("Whole stack: %.8g", last);
                while (check_stack())
                    printf(" %.8g", pop());
            }
            else {
                printf("%.8g", last);
                if (print) {
                    push(last);
                    print = 0;
                }
            }
        }
        putchar('\n');
        return 0;
    }

    /* interactive calculator */
    printf("ULTIMATE REVERSE POLISH CALCULATOR V2.0 (URVPC2)\nUse `help` for available features.\n>> ");
    while ((get_line(line, MAXLINE)) > 0) {
        line_pos=0;
        while (read_word(line, word) > 0)
            if (execute_word(word)) {
                return 0;
                putchar('\n');
            }
        if (check_stack()) {
            last = pop();
            printf("\t%.8g\n", last);
            if (print) {
                push(last);
                print = 0;
            }
        }
        printf(">> ");
    }
    putchar('\n');
    return 0;
}
int execute_word(char word[]) {
    int type;
    double op1, op2;
    static double vars[26];
    switch ((type = optype(word))) {
        case NUMBER:
            push(atof(word));
            break;
        case PLUS:
            push(pop() + pop());
            break;
        case MUL:
            push(pop() * pop());
            break;
        case MINUS:
            op2 = pop();
            push(pop() - op2);
            break;
        case DIV:
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor");
            break;
        case REM:
            op2 = pop();
            if (op2 != 0.0)
                push((int) pop() % (int) op2);
            else
                printf("error: zero divisor");
            break;
        case PRNT:
            print = 1;
            break;
        case DUP:
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case SWP:
            op1 = pop();
            op2 = pop();
            push(op1);
            push(op2);
            break;
        case CLR:
            clear();
            break;
        case SIN:
            push(sin(pop()));
            break;
        case COS:
            push(cos(pop()));
            break;
        case TAN:
            push(tan(pop()));
            break;
        case SQRT:
            push(sqrt(pop()));
            break;
        case EXP:
            push(exp(pop()));
            break;
        case POW:
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case WRITE:
            if (strlen(word) != 2) printf("error: only single-letter names for variables are allowed.\nName given: %s\n", word);
            else
            if ('a' <= word[1] && word[1] <= 'z')
                vars[word[1] - 'a'] = pop();
            break;
        case READ:
            if (strlen(word) != 2) printf("error: only single-letter names for variables are allowed.\nName given: %s\n", word);
            else
            if ('a' <= word[1] && word[1] <= 'z')
                push(vars[word[1] - 'a']);
            else if (word[1] == '?')
                push(last);
            else printf("error: unknown variable name %c\n", word[1]);
            break;
        case UNKWN_CMD:
            printf("error: unknown command %s\n", word);
            break;
        case CLRSCR:
            system(clrscr);
            break;
        case EXIT:
            return 1;
            break;
        case HELP:
            print_help();
            break;
        default:
            printf("error: unhandled op with number %d for `%s`", type, word);
            break;
    }
    return 0;
}


int read_word(char line[], char word[]) {
    int j = 0;
    while (line[line_pos] == ' ' || line[line_pos] == '\t')
        line_pos++;

    while (!isspace(line[line_pos]) && line[line_pos] != '\0')
        word[j++] = line[line_pos++];

    word[j] = '\0';
    return j;
}

int optype(char word[]) {
    if (strcmp(word, "+") == 0) return PLUS;
    else if (strcmp(word, "-") == 0) return MINUS;
    else if (strcmp(word, "*") == 0) return MUL;
    else if (strcmp(word, "/") == 0) return DIV;
    else if (strcmp(word, "%") == 0) return REM;
    else if (strcmp(word, "p") == 0) return PRNT;
    else if (strcmp(word, "dup") == 0) return DUP;
    else if (strcmp(word, "swp") == 0) return SWP;
    else if (strcmp(word, "clr") == 0) return CLR;
    else if (strcmp(word, "sin") == 0) return SIN;
    else if (strcmp(word, "cos") == 0) return COS;
    else if (strcmp(word, "tan") == 0) return TAN;
    else if (strcmp(word, "sqrt") == 0) return SQRT;
    else if (strcmp(word, "exp") == 0) return EXP;
    else if (strcmp(word, "pow") == 0) return POW;
    else if (strcmp(word, "exit") == 0) return EXIT;
    else if (strcmp(word, "clear") == 0) return CLRSCR;
    else if (strcmp(word, "help") == 0) return HELP;
    else if (word[0] == '$') return READ;
    else if (word[0] == '@') return WRITE;
    else if (isdigit(word[0]) || word[0] == '+' || word[0] == '-' || word[0] == '.') return NUMBER;
    else return UNKWN_CMD; 
}

#define MAXVAL 256
int sp=0;
double values[MAXVAL];

void push(double f) {
    if (sp < MAXVAL) {
        values[sp++] = f;
#ifdef tracing
        if (tracing) printf("pushed %lf\n", f);
#endif
    }
    else printf("error: stack values limit reached\n");
}

int check_stack(void) {
    return sp > 0;
}

double pop(void) {
    if (sp > 0) {
        --sp;
#ifdef tracing
        if (tracing) printf("popped %lf\n", values[sp]);
#endif
        return values[sp];
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void clear(void) {
    sp = 0;
}

void print_help(void) {
    puts("\nThis calculator uses reverse polish notation.\n"
"For example, use '34 35 +' for 34 + 35 or '1 2 - 4 5 + *' for (1 - 2) * (4 + 5)\n"
"Typing in a number pushes it on top of the stack.\n"
"Press Enter to evaluate the expression and print the value on top of the stack.\n"
"Press Ctrl-D (i. e. EOF) to exit.\n\n"
"Available commands:\n"
"'help' - print this guide.\n"
"'p' - print the value without popping it.\n"
"'+', '*' - addition, multiplication.\n"
"'-', '/', '%%' - subtraction, division and the remainder, work as follows:\n"
"'x y -' is equivalent to 'x - y' in infix notation.\n"
"'dup' - duplicate the value on top of the stack.\n"
"'swp' - swap two values on top of the stack.\n"
"'clr' - clear the stack.\n"
"'sin, cos, tan' - return the sin, cos and tan of the operand respectively.\n"
"'exp' - returns the value of e raised to the power of the operand.\n"
"'x y pow' - returns the value of x raised to the power of y.\n"
"'clear' - clear the terminal screen.\n\n"
"Variables:\n"
"Use '@x' to write a value on top of the stack into a variable called x.\n"
"Any one-letter name is allowed.\n"
"Use '$x' to read the value from a variable and push it on top of the stack.\n"
"There is a special variable '$?' which stores the last printed value."
);
    
}

int get_line(char line[], int max) {
    int c, i = 0;
    while (i + 1 < max && (c = getchar()) != EOF && c != '\n')
        line[i++] = c;
    if (c == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return i;
};

