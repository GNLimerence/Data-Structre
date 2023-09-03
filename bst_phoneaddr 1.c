/*
    Pham Hoang Hai Nam
    MSSV: 20215099
    Ngay Hoan Thanh: 22/12/2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct phoneAddr_s
{
    char name[20];
    char tel[12];
    char email[28];
}phoneAddr_t;
typedef phoneAddr_t data_t;
typedef struct node_s {
  data_t key;
  struct node_s *left;
  struct node_s *right;
} node_t;
typedef node_t *tree_t;
/*int compare(data_t x, data_t y) { // so sanh 2 item theo key
    return strcmp(x.email, y.email);
}*/
void showData(tree_t data)
{
    printf("name: %s | tel: %s| email: %s  ", data->key.name, data->key.tel, data->key.email);
    printf("\n");
}
tree_t search( char x[], tree_t root) {
  if (root == NULL)
    return NULL;           // not found
  else if (strcmp(root->key.email,x) == 0) /* found x */
    return root;
  else if (strcmp(root->key.email,x) < 0)
    // continue searching in the right sub tree
    return search(x, root->right);
  else {
    // continue searching in the left sub tree
    return search(x, root->left);
  }
}
void insertNode(data_t x, tree_t *pRoot) {
  if (*pRoot == NULL) {
    /* Create a new node for key x */
    *pRoot = (node_t *)malloc(sizeof(node_t));
    (*pRoot)->key = x;
    (*pRoot)->left = NULL;
    (*pRoot)->right = NULL;
  } else if (strcmp((*pRoot)->key.email,x.email) > 0)
    insertNode(x, &((*pRoot)->left));
  else if (strcmp((*pRoot)->key.email,x.email) < 0)
    insertNode(x, &((*pRoot)->right));
}
// Find the left-most node of right sub tree
// Delete a node from a BST
void prettyPrint(tree_t tree) {
  static char prefix[200] = "    ";
  char *prefixend = prefix + strlen(prefix);
  if (tree != NULL) {
    printf("%04s",tree->key.email);
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
int main (){
    tree_t tree = NULL;
    data_t a[]={{"E", "023123", "E@"},
                {"H", "032731", "H@"},
                {"G", "138123", "G@"},
                {"I", "128319", "I@"},
                {"A", "123891", "A@"},
                {"F", "025143", "F@"},
                {"C", "052831", "C@"},
                {"B", "148623", "B@"},
                {"D", "178315", "D@"},
                {"K", "163841", "K@"}};
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++){
        insertNode(a[i],&tree);
    }
    prettyPrint(tree);
    tree_t p;
    char n[28];
    printf("\n Nhap vao Email muon tim: \n");
    scanf("%s",&n);
    p = search(n,tree);
    if (p != NULL){
        showData(p);
    }else{
    printf("Khong tim thay");
    }
    freeTree(tree);            
    return 0;
}