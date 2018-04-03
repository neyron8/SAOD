#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

int main()
{
	bstree * test;
    test = bstree_create("jacko", 45);
	printf("%d", test -> value);

    return 0;
}
