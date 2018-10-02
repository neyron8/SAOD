#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int key;
  struct Node *left;
  struct Node *right;
  int height;
  int delete;
} Node;

int height(Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) { return (a > b) ? a : b; }

Node *newNode(int key) {
  Node *node = malloc(sizeof(Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  node->delete = 0;
  return (node);
}

Node *rightRotate(Node *y) {
  Node* left;

  left = y -> left;
  y -> left = left -> right;
  left->right = y;

  y->height = max(height(y->left), height(y->right)) + 1;
  left->height = max(height(left->left), y -> height) + 1;

  return left;
}

Node *leftRotate(Node *x) {
  Node* right;

  right = x -> right;
  x -> right = right -> left;
  right->left = x;

  x->height = max(height(x->left), height(x->right)) + 1;
  right->height = max(height(right->right), x -> height) + 1;

  return right;
}

int getBalance(Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

Node *insert(Node *node, int key) {
  if (node == NULL)
    return (newNode(key));

  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);
  else
    return node;

  node->height = 1 + max(height(node->left), height(node->right));

  int balance = getBalance(node);

  // Left Left
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);

  // Right Right
  if (balance < -1 && key > node->right->key)
    return leftRotate(node);

  // Left Right
  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  // Right Left
  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

Node *lookup(Node *tree, int key) {
  while (tree != NULL) {
    if (key == tree->key) {
      return tree;
    } else if (key < tree->key) {
      tree = tree->left;
    } else {
      tree = tree->right;
    }
  }
  return tree;
}

void delete_node(Node *tree, int *i, int first[], int key) {
  if (tree == NULL)
    return;
  *i = *i + 1;
  Node *del = lookup(tree, key);
  del->delete = 1;
  if (*i > 3) {
    *i = 0;
    new_tree(tree, i, first);
  }
}

void new_tree(Node *tree, int *i, int first[]) {
  if (tree == NULL)
    return;
  if (tree->delete != 1) {
    first[*i] = tree->key;
    *i = *i + 1;
  }
  new_tree(tree->left, i, first);
  new_tree(tree->right, i, first);
}

void avltree_free(Node *tree) {
  if (tree == NULL)
    return;
  avltree_free(tree->left);
  avltree_free(tree->right);
  free(tree);
}

void avltree_print_dfs(Node *tree, int level) {
  int i;
  if (tree == NULL)
    return;
  for (i = 0; i < level; i++)
    printf(" ");
  printf("%d\n", tree->key);
  avltree_print_dfs(tree->left, level + 1);
  avltree_print_dfs(tree->right, level + 1);
}

Node *minimum(Node *tree) {
  if (tree == NULL) {
    return NULL;
  }

  Node *x = minimum(tree->left);

  if (x != NULL) {
    return x;
  }

  if (tree->delete != 1) {
    return tree;
  }
  return minimum(tree->right);
}

Node *maximum(Node *tree) {

  if (tree == NULL) {
    return NULL;
  }

  Node *x = minimum(tree->right);

  if (x != NULL) {
    return x;
  }

  if (tree->delete != 1) {
    return tree;
  }
  return maximum(tree->left);
}

int main() {

  Node *root = NULL;

  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);

  avltree_print_dfs(root, 0);

  Node *look = NULL;
  int i = 0, y;
  int first[10];
  delete_node(root, &i, first, 10);
  delete_node(root, &i, first, 20);
  delete_node(root, &i, first, 30);
  delete_node(root, &i, first, 40);

  Node *mini = minimum(root);
  printf("%d", mini->key);

  for (y = 0; y < i; y++) {
    look = insert(look, first[y]);
  }

  return 0;
}
