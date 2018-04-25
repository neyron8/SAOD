#ifndef HASHTAB_C
#define HASHTAB_C

#define SIZE 10000
#define HASH_MUL 31

typedef struct {
	char *key;
	int value;
	
	struct node *next;
} node;

typedef struct {       
    struct node **list; 
} hash_table;

unsigned int hashtab_hash (char*key, unsigned int mod);
hash_table *hashtab_init(hash_table *hashtab);
void hashtab_add(hash_table *hashtab, char *key, int value);
node *hashtab_lookup(hash_table *hashtab, char *key);
void hashtab_delete(hash_table *hashtab, char *key);
int hashtab_coll(hash_table *hashtab);

#endif
