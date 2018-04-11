#ifndef BSTREE_C
#define BSTREE_C

typedef struct
{
	char *key;
	struct bstree *left;
	struct bstree *right;
	struct bstree *top;

}bstree;

typedef struct
{
  char *field; 
  struct list *ptr; 

} list;

bstree *bstree_create (bstree *root,char *key);
void bstree_add (bstree *tree, char *key);
bstree *bstree_lookup (bstree *tree, char *key);
bstree *bstree_min (bstree *tree);
bstree *bstree_max (bstree *tree); 
bstree *bstree_create_root(char *key4f);

#endif
