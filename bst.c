// BST: Bin Search Tree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

tree_t search(key_t x, tree_t root) {
  if (root == NULL)
    return NULL;           // not found
  else if (root->key == x) /* found x */
    return root;
  else if (root->key < x)
    // continue searching in the right sub tree
    return search(x, root->right);
  else {
    // continue searching in the left sub tree
    return search(x, root->left);
  }
}

void insertNode(key_t x, tree_t *pRoot) {
  if (*pRoot == NULL) {
    /* Create a new node for key x */
    *pRoot = (node_t *)malloc(sizeof(node_t));
    (*pRoot)->key = x;
    (*pRoot)->left = NULL;
    (*pRoot)->right = NULL;
  } else if (x < (*pRoot)->key)
    insertNode(x, &((*pRoot)->left));
  else if (x > (*pRoot)->key)
    insertNode(x, &((*pRoot)->right));
}

// Find the left-most node of right sub tree
key_t deleteMin(tree_t *root) {
  if ((*root)->left == NULL) {
    key_t k = (*root)->key;
    (*root) = (*root)->right;
    return k;
  } else
    return deleteMin(&(*root)->left);
}

// Delete a node from a BST
void deleteNode(key_t x, tree_t *root) {
  if (*root != NULL)
    if (x < (*root)->key)
      deleteNode(x, &(*root)->left);
    else if ((*root)->key < x)
      deleteNode(x, &(*root)->right);
    else if (((*root)->left == NULL) && ((*root)->right == NULL))
      *root = NULL;
    else if ((*root)->left == NULL)
      *root = (*root)->right;
    else if ((*root)->right == NULL)
      *root = (*root)->left;
    else
      (*root)->key = deleteMin(&(*root)->right);
}

void prettyPrint(tree_t tree) {
  static char prefix[200] = "    ";
  char *prefixend = prefix + strlen(prefix);
  if (tree != NULL) {
    printf("%04d", tree->key);
    if (tree->left != NULL)
      if (tree->right == NULL) {
        printf("\304");
        strcat(prefix, "     ");
      } else {
        printf("\302");
        strcat(prefix, "\263    ");
      }
    prettyPrint(tree->left);
    *prefixend = '\0';
    if (tree->right != NULL)
      if (tree->left != NULL) {
        printf("\n%s", prefix);
        printf("\300");
      } else
        printf("\304");
    strcat(prefix, "     ");
    prettyPrint(tree->right);
  }
}

void freeTree(tree_t tree) {
  if (tree != NULL) {
    freeTree(tree->left);
    freeTree(tree->right);
    free((void *)tree);
  }
}