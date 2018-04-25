#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashtab.h"
#include <time.h>

#define HASH_MUL 31
#define SIZE 10000

int main() 
{
	
   	FILE *file;
    hash_table *man;
	node *look;
	man = hashtab_init(man);
	char word[50];
    file = fopen ("gf.txt","r");
	
	char c;
	int i = 0;
    
	for(i; i < 10000; i++ ) {
        c = fscanf(file, "%s", word);
        int ln = strlen(word) - 1;
        if (word[ln] == '\n')
            word[ln] = '\0';
		printf("%s\n", word);
        hashtab_add(man, word, 5);

	}
	
	fclose(file);
	
	look = hashtab_lookup(man, "anatole");
	printf("%s", look -> key);
	return 0;
}
