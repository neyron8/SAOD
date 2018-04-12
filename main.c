#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

int main()
{
	bstree * test;
	bstree * find;
    test = bstree_create_root("jacko");
	bstree_add(test,"fdfdfdfd");
	bstree_add(test,"sh");
	bstree_add(test,"cvxz");
	bstree_add(test,"cv");
	bstree_add(test,"arrt");
	bstree_add(test,"kjh");
	bstree_add(test,"jackodfgdfg");
	bstree_add(test,"jackodfgdfgccvbv");
	bstree_add(test,"dfdfhcvcv");
	find = bstree_lookup(test, "arrt");
	printf("HERE WE GO %s\n", find -> key);
	
	treeprint(test);
	
    return 0;
}
