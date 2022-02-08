#ifndef PREPROCESS_H_INCLUDED
#define PREPROCESS_H_INCLUDED


struct nlist *lookup(char *);
struct nlist *install(char *, char *);
struct nlist *rem(char *);

struct nlist {
	char *name;
	struct nlist *next;
	char *val;
};

#endif
