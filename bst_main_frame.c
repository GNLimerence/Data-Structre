/*Pham Hoang Hai Nam
MSSV: 20215099
Ngay Hoan Thanh: 14/12/2022
*/
// Exercise
// - Create an binary search tree with 10 nodes. Each node contains an random integer. 
// - Ask user to input an number and search for it.
// - Print the content of the trees. 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"
int main() {
  tree_t tree = NULL;
  srand((int)time(NULL));
  int r[10];
  // Create an binary search tree with 10 nodes.
  // Each node contains an random integer.
  // --- Your code here ---
  for (int i = 0 ; i < 10 ; i++)
  {
      r[i] = rand();
      insertNode(r[i],&tree);
  }
  // Print the content of the trees. 
  prettyPrint(tree);  printf("\n");

  int n = 0;  // n: user's input
  printf("Enter key to search (-1 to quit):");
  scanf("%d",&n);
  while(n != -1) {
    tree_t p;
    // Search 
    // --- Your code here ---
    p = search(n,tree);
    if (p != NULL)
      printf("Key %d found on the tree\n\n", n);
    else {
      insertNode(n, &tree);
      prettyPrint(tree);
    }
    // Ask user to input an number and search for it.
    printf("\nEnter key to search (-1 to quit):");
    scanf("%d",&n);
  }
  freeTree(tree);

  return EXIT_SUCCESS;
}