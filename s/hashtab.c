#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashtab.h"

#define HASH_MUL 31
#define SIZE 10000

unsigned int hashtab_hash (char*key, unsigned int mod) 
{
	unsigned int h = 0, g;
	while(*key) {

    h = (h << 4) + *key++;
    g = h & 0xf0000000L;

    if(g) {
        h ^= g >> 24;
	}

    h &= ~g;
	}

	return h % mod;
}

hash_table *hashtab_init ( hash_table *hashtable ) 
{

	hashtable = malloc(sizeof(hash_table));
	
	hashtable -> list = malloc(sizeof(hash_table) * SIZE);
	
	int i;
	
	for (i = 0; i < SIZE; i++) {
		hashtable -> list[i] = NULL;
	}
	return hashtable;
}

void hashtab_add(hash_table *hashtab, char *key, int value)
{
	node *hashnode;
	int index = hashtab_hash (key,25);

	hashnode = malloc(sizeof(node));
	if (hashnode != NULL) {
		hashnode -> key = strdup(key);
		hashnode -> value = value;
	
		if (hashtab ->list[index] != NULL){
			hashnode -> next = hashtab -> list[index];
		} else {
			hashnode -> next = NULL;
		}
		hashtab -> list [index] = hashnode;
	}
}

node *hashtab_lookup(hash_table *hashtab, char *key)
{
	int index;
	node *hashnode;

	index = hashtab_hash(key,25);
	printf("%d\n", index);
	for (hashnode = hashtab -> list[index]; hashnode != NULL; hashnode = hashnode -> next) {
		if (strcmp (hashnode -> key, key) == 0) {
			return hashnode;
		}
	}
	return NULL;
}

hashtab_delete(hash_table *hashtab, char *key)
{
	node *delete;
	node *prev = NULL;
	int index;

	index = hashtab_hash(key,25);
	for (delete = hashtab -> list[index]; delete != NULL; delete = delete -> next) {
		if (strcmp (delete -> key, key) == 0) {
			if (prev == NULL) {
				hashtab -> list[index] = delete -> next;
			} else {
				prev -> next = delete -> next;
			}
			free(delete);
			printf("\nElement deleted\n");
			return;
						
		}
		prev = delete;
	}
} 		

int hashtab_coll(hash_table *hashtab)
{
	int index;
	node *hashnode;
	int count = 0, col = 0;
	for (count;count < SIZE;){
		for (hashnode = hashtab -> list[count]; hashnode != NULL;hashnode = hashnode -> next) {	
					col++;
		}
		count++;
 		col--;
	}
			
	return col;
}







