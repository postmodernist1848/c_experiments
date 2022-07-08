/* freq - count and print words sorted by the number of occurences */
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

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof (struct tnode));
}

int g_node_count;

/* addtreee: add a node or increment count of tnode with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {
    int cond;

    if (p == NULL) {
        g_node_count++;
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

void treetoarray(struct tnode *p, struct tnode * array[]) {
    static int i;
    if (p != NULL) {
        treetoarray(p->left, array);
        array[i++] = p;
        treetoarray(p->right, array);
    }
}

/*get a word without pucntuation marks*/
int getword(char *word, int max) {
    int c = 0;
    int i = 0;

    while (!isalpha(c = getchar()) && c != EOF);
    if (c == EOF) return c;
    while (isalpha(c) && i + 1 < max && c != EOF) {
        word[i++] = c;
        c = getchar();
    }
    word[i] = '\0';
    return i;
}

int treecountcmp(const void *leaf1, const void *leaf2) {
    return (*(struct tnode **) leaf2)->count - (*(struct tnode **)leaf1)->count;
}

int main (void) {

    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while(getword(word, MAXWORD) != EOF)
        root = addtree(root, word);

    struct tnode *tree_arr[g_node_count];
    treetoarray(root, tree_arr);

    qsort(tree_arr, g_node_count, sizeof(struct tnode *), treecountcmp);

    for (int i = 0; i < g_node_count; i++) {
        printf("%d: %s\n", tree_arr[i]->count, tree_arr[i]->word);
    }
    return 0;
}
