#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

int main()
{
	bstree * test;
	bstree * find;
    test = bstree_create_root("TEST");
	printf("\n");
	printf("%s\n", test -> key);
	bstree_add(test,"fdfdfdfd");
	test = test ->right;
	printf("%s", test ->key);
	bstree_add(test,"sh");
	find = bstree_lookup(test, "sh");
	printf("%s", find -> key);

    return 0;
}
