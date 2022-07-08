#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 128
#define MAXLINENUMBERS 100

struct tnode {
    char *word;
    int count;
    int line_counts[MAXLINENUMBERS];
    struct tnode *left;
    struct tnode *right;
};

int is_pos_int(char * num) {
    for (int i = 0; num[i]; i++)
        if (!isdigit(num[i])) return 0;
    return 1;

}

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof (struct tnode));
}


/* addtreee add a node or increment count of tnode with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w, int ln) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
        p->line_counts[0] = ln; 
    } else if ((cond = strcmp(w, p->word)) == 0) {
        p->line_counts[p->count++] = ln;
    }
    else if (cond < 0)
        p->left = addtree(p->left, w, ln);
    else p->right = addtree(p->right, w, ln);
    return p;
}


void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%s:", p->word);
        for (int i=0; i < p->count; i++)
            printf(" %d", p->line_counts[i] + 1);
        putchar('\n');
        treeprint(p->right);
    }
}


/*get a word without pucntuation marks*/
int getword(char *word, int max) {
    static int line_number;
    static int c;
    int i = 0;

    if (c == '\n') line_number++;

    while (!isalpha(c = getchar()) && c != EOF)
        if (c == '\n') line_number++;
    if (c == EOF) return c;
    while (isalpha(c) && i + 1 < max && c != EOF) {
        word[i++] = c;
        c = getchar();
    }
    word[i] = '\0';


    return line_number;
}

int iscapitalized(char * word) {
    for (int i=0; word[i]; i++) {
        if (islower(word[i]))
            return 0;
    }
    return 1;
}

int isimportant(char *word) {
    int len = strlen(word);
    return len > 3 || (len > 1 && iscapitalized(word));
}

int main (void) {

    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    int line_number;
    while((line_number = getword(word, MAXWORD)) != EOF)
        if (isimportant(word))
            root = addtree(root, word, line_number);
    treeprint(root);
    return 0;
}
/*
C (/ˈsiː/, as in the letter c) is a general-purpose computer programming language. 
It was created in the 1970s by Dennis Ritchie, and remains very widely used and influential.
By design, C's features cleanly reflect the capabilities of the targeted CPUs.
It has found lasting use in operating systems, device drivers, protocol stacks, though decreasingly for application software, and is common in computer architectures that range from the largest supercomputers to the smallest microcontrollers and embedded systems.


A successor to the programming language B, C was originally developed at Bell Labs by Dennis Ritchie between 1972 and 1973 to construct utilities running on Unix.
It was applied to re-implementing the kernel of the Unix operating system.
[6] During the 1980s, C gradually gained popularity.
It has become one of the most widely used programming languages,[7][8] with C compilers available for almost all modern computer architectures and operating systems.
C has been standardized by ANSI since 1989 (ANSI C) and by the International Organization for Standardization (ISO).
*/
