#ifndef __BST_H__
#define __BST_H__

typedef int key_t;  // specify a type for the data

typedef struct node_s {
  key_t key;
  struct node_s *left;
  struct node_s *right;
} node_t;

typedef node_t *tree_t;

tree_t search(key_t x, tree_t Root);
void insertNode(key_t x, tree_t *pRoot);
key_t deleteMin(tree_t *Root);
void deleteNode(key_t x, tree_t *Root);
void prettyPrint(tree_t tree);
void freeTree(tree_t tree);

#endif