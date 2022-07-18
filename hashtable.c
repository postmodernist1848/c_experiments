/* a simple hashtable implementation inspired by K&R book */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashtable.h"

unsigned hash(char *s, size_t hashsize) {
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % hashsize;
}

ListNode *lookup (char *s, Hashtable *hashtab) {
    ListNode *np;

    for (np = hashtab->hashtab[hash(s, hashtab->hashsize)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

ListNode *install(char *name, char *defn, Hashtable *hashtab) {
    ListNode *np;
    unsigned hashval;

    if ((np = lookup(name, hashtab)) == NULL) { np = (ListNode *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name, hashtab->hashsize);
        np->next = hashtab->hashtab[hashval];
        hashtab->hashtab[hashval] = np;
        } else
            free((void *) np->defn);
        if ((np->defn = strdup(defn)) == NULL)
            return NULL;
        return np;
    }

int undef(char *name, Hashtable *hashtab)
{
  ListNode *node_p;
  ListNode *prev_node_p;
  size_t hash_value = hash(name, hashtab->hashsize);
  for (node_p = hashtab->hashtab[hash_value], prev_node_p = NULL;
       node_p != NULL;
       prev_node_p = node_p, node_p = node_p->next)
  {
    if (strcmp(name, node_p->name) == 0)
    {
      free(node_p->name);
      free(node_p->defn);

      if (prev_node_p == NULL)
      {
        hashtab->hashtab[hash_value] = node_p->next;
      }
      else
      {
        prev_node_p->next = node_p->next;
      }

      free(node_p);
      return 1;
    }
  }

  return 0;
}

Hashtable *create_hashtable(size_t hashsize) {

    Hashtable *hashtable = (Hashtable *) malloc(sizeof(Hashtable));       //hashtable struct is malloced
    hashtable->hashsize = hashsize;
    ListNode **hashtab = (ListNode **) malloc(hashsize * sizeof(ListNode *));      //hashtab array is malloced
    memset(hashtab, 0, hashsize * sizeof(ListNode *));
    hashtable->hashtab = hashtab;

    return hashtable;
}




//test function, might get deleted from library
void print_value_of(char *key, Hashtable *hashtab) {
    ListNode *value = lookup(key, hashtab);
    if (value)
        printf("'%s' -> '%s'\n", key, value->defn);
    else printf("Key \"%s\" not found.\n", key);
}
