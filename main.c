#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

int main()
{
	bstree * test;
	bstree * find;
    test = bstree_create("jacko", 43);
	bstree_add(test,"fdfdfdfd", 13);
	bstree_add(test,"sh", 154);
	bstree_add(test,"cvxz", 123);
	bstree_add(test,"cv", 5);
	bstree_add(test,"arrt", 76);
	bstree_add(test,"kjh", 1893);
	bstree_add(test,"jackodfgdfg", 12333);
	bstree_add(test,"jackodfgdfgccvbv", 1093);
	bstree_add(test,"dfdfhcvcv", 12313);
	bstree_add(test,"999999999999", 12313);
	treeprint(test);
	find = bstree_max (test);
	printf("MINIMUM  %s", find -> key);	
	
    return 0;
}
