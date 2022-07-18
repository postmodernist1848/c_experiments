#include <stdlib.h>

typedef struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
} ListNode;

typedef struct hashtable {
    size_t hashsize;
    struct nlist **hashtab;
} Hashtable;

Hashtable *create_hashtable(size_t hashsize);
ListNode *install(char *name, char *defn, Hashtable *hashtab);
ListNode *lookup (char *s, Hashtable *hashtab);
int undef(char *name, Hashtable *hashtab);

//possibly unneeded functions
unsigned hash(char *s, size_t hashsize);
void print_value_of(char *key, Hashtable *hashtab);
