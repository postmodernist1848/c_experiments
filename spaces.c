#include <stdio.h>
#define IN 1
#define OUT 0

int main1_9_10(void) {
    int c, blanks=0;
    char prev_c = 0;
    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\n' || c == '\t')
            blanks++;
        if (!(c == ' ' && prev_c == ' '))
            putchar(c);
        prev_c = c;}
    printf("\nYour input contains %d spaces\n", blanks);
return 0;
}


int main1_9(void) {
    int c, replacements;
    while ((c = getchar()) != EOF){
        switch (c) {
            case '\t': printf("\\t"); replacements++; break;
            case '\\': printf("\\\\"); replacements++; break;
            case '\b': printf("\\b"); replacements++; break;
            default: putchar(c); break;
        }
        }
    printf("%d characters have been replaced.", replacements);
return 0;
}

int main(void) {
    int c, state = OUT;
    while ((c = getchar()) != EOF){
       if ((c == ' ' || c == '\t' || c == '\n') && state == IN)
            {
                putchar('\n');
                state = OUT;
            }       
       else {putchar(c); state = IN;}
        }
return 0;
}