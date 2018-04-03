#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"


bstree *bstree_create(char *key4f, int value4f) 
{
	bstree *element;
	
	element = malloc( sizeof (*element) );
	if (element == NULL) 
	{ 
		printf("\nError of creating\n");
		return -1;

	} else {

		element ->key = strdup (key4f);
		element -> left = NULL;
		element -> right = NULL;
		element -> value = value4f;
		printf("%d", element -> value);
	}
	printf("\nALL DONE!");
	return element;

}
