#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define DEFAULT_N 6
#define MAXWORD 128

struct tnode {
    char *word;
    int count;
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
struct tnode *addtree(struct tnode *p, char *w) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p-> count++;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else p->right = addtree(p->right, w);
    return p;
}

void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

/*get a word without pucntuation marks, excluding string and C comments */
int getword(char *word, int max) {
    int c = 0;
    int i = 0;
    int prev_c;
    while (!isalpha(c = getchar()) && c != EOF) {
        // skip string in " "
        if (c == '"') {
            while((c = getchar()) != '"') if (c == EOF) return c;
        }
        //skip comment in /* */
        if (prev_c == '/' && c == '*') {
            while (!(prev_c == '*' && c == '/') && c != EOF) {
                prev_c = c;
                c = getchar();
                if (c == EOF) return c;
            }
        }
        //skip comment after //
        if (prev_c == '/' && c == '/')
            while ((c = getchar()) != '\n') if (c == EOF) return c;

        prev_c = c;
    }
    if (c == EOF) return c;
    while (isalpha(c) && i + 1 < max && c != EOF) {
        word[i++] = c;
        c = getchar();
    }
    word[i] = '\0';
    return i;
}

char *first(char *str, size_t n) {
    if (strlen(str) > n) 
        str[n] = '\0';
    return str;
}


/* print sorted list of groups of words (groups are determined by n first characters) */
int main (int argc, char *argv[]) {
    int n;
    if (argc == 2)
        if (argv[1][0] == '-' && is_pos_int(argv[1] + 1)) {
        n = atoi(argv[1] + 1);
        }
        else { printf("hereUsage: canal -n\n"); return 1; }
    else n = DEFAULT_N;
    if (argc > 2) { printf("Usage: canal -n\n"); return 1; }

    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while(getword(word, MAXWORD) != EOF)
        root = addtree(root, first(word, n));
    treeprint(root);
    return 0;
}
