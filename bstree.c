#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"


bstree *bstree_create_root(char *key4f) 
{
	bstree *element;
	
	element = malloc( sizeof (*element) );
	if (element == NULL) 
	{ 
		printf("\nError of creating\n");
		return -1;

	} else {

		element -> key = strdup(key4f);;
		element -> left = NULL;
		element -> right = NULL;
		
	}
	return element;

}

bstree *bstree_create(bstree *root,char *key4f) 
{
	bstree *element;
	
	element = malloc( sizeof (*element) );
	if (element == NULL) 
	{ 
		printf("\nError of creating\n");
		return -1;

	} else {

		element -> key = strdup(key4f);;
		element -> left = NULL;
		element -> right = NULL;
		element -> top = root;
	}
	return element;

}

bstree_add(bstree *tree, char *key4f)
{
	bstree *parent;
	bstree *element;
	
	if(tree == NULL) {
		return;
	}
	
	for (parent = tree; tree != NULL;) {
		parent = tree;
		if (strcmp(key4f,tree-> key) < 0) {
			tree = tree -> left;
		}
		else if(strcmp(key4f, tree -> key) > 0){
			tree = tree -> right;
		}
		else
			return;
	}

	element = bstree_create(tree, key4f);
	
	if (strcmp(key4f, parent-> key) < 0) {
		parent -> left = element;
		printf("\nleft\n");
	} else {
		parent -> right = element;
		printf("\nright\n");
	}	
	
}

bstree *bstree_lookup (bstree *tree, char *key) {

	bstree *detector;
	detector = tree;
	while (detector != NULL) {
		if (strcmp(key, detector-> key) == 0 ) {
			return detector;
		}
		else if (strcmp(key, detector-> key) < 0) {
			detector = detector -> left;
		}
		else if (strcmp(key, detector-> key) > 0) {
			detector = detector -> right;
		}
	}
	return detector;
}
