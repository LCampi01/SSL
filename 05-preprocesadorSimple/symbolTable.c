#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "symbolTable.h"

static struct nlist *hashtab[100];

int hash(char *s) {
	int hashval;
	for (hashval = 0;  *s != '\0'; )
		hashval += *s++;
	return (hashval % 100);
}
struct nlist *lookup(char *s) {
	struct nlist *np;
	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return(np);
	return(NULL);
}
struct nlist *install(char *name, char *value) {
	struct nlist *np, *lookup();
	int hashval;
	if ((np = lookup(name))  == NULL) {
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL)
			return(NULL);
		if ((np->name = strdup(name)) == NULL)
			return(NULL);
		hashval = hash(np->name);
		if ((np->val = strdup(value)) == NULL)
        	return(NULL);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	return(np);
}
struct nlist *rem(char *name) {
    struct nlist *found;
    found = lookup(name);
    if (found == NULL)
        return NULL;
    else {
        if (found->next != NULL) {
            found->next = found->next->next;
            found = found->next;
        } else {
            hashtab[hash(name)] = NULL;
            free((void *) found);
        }
    }
    return found;
}
