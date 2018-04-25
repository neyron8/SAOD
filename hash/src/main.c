#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashtab.h"

#define HASH_MUL 31
#define SIZE 50000

int main() 
{
	
	
   	FILE *file;
    hash_table *man;
	node *look;
	
	char word[50];
    file = fopen ("gf.txt","r");
	
	char c;
	int i = 0;
	int p = 0;

	man = hashtab_init (man);

    for(i; i < SIZE; i++ )
		{
        c = fscanf(file, "%s", word);
        int ln = strlen(word) - 1;
        if (word[ln] == '\n')
            word[ln] = '\0';
        hashtab_add(man, word, 5, &p);
	}
	printf("%d", p);
	fclose(file);
	
	return 0;
}
