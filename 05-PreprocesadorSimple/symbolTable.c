struct symbolNode {
    struct symbolNode *next;
    char *id;
    char *value;
};

const int HASHSIZE 101;
static struct symbolNode *hashtab[HASHSIZE];

unsigned hash(char *s) {
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
      hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct symbolNode *find(char *s) {
    struct symbolNode *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->id) == 0)
          return np;
    return NULL;
}

char *duplicateString(char *s)
{
    char *p;
    p = (char *) malloc(strlen(s)+1);
    if (p != NULL)
       strcpy(p, s);
    return p;
}
struct symbolNode *add(char *name, char *defn) {
    struct symbolNode *np;
    unsigned hashval;
    if ((np = find(name)) == NULL) {
        np = (struct symbolNode *) malloc(sizeof(*np));
        if (np == NULL || (np->name = duplicateString(name)) == NULL)
          return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free((void *) np->defn);
    if ((np->defn = duplicateString(defn)) == NULL)
       return NULL;
    return np;
}

void *remove (char* id) {
    struct symbolNode  *aux, *np;
    np = hashtab[hash(s)];
    aux = np->next;
    if (strcmp(s, np->id) == 0) {
            hashtab[hash(id)] = np -> next
            free((void*) np);
            return;
        }
    while (np != NULL) {
        if (strcmp(s, aux->id) == 0) {
            np->next = aux->next;
            free((void*) aux);
            return;
        }
        aux = aux->next;
        np = np->next;
    }
    return NULL;

}