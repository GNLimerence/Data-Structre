/*
Pham Hoang Hai Nam
20215099
Ngay hoan thanh: 21/2/2023
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

element_t* ht[TABLE_SIZE];

int main() {
  const char* keys[] = {"John Smith", "Lisa Smith", "Sam Doe", "Sandra Dee"};
  // const char* keys[] = {"John Smith", "Lisa Smith", "Sam Doe"};
  // const char* keys[] = {"Lisa Smith", "Sandra Dee"};
  element_t e;
  element_t *p;
  for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
    printf("(key, hash(key)) = (%s, %d)\n",keys[i], hash(keys[i]));
  }

  init_table(ht);
  for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
    //element_t e;
    strcpy(e.key, keys[i]);
    strcpy(e.word, keys[i]);
    e.next = NULL;
    insertItem(ht, e);
  }

  printf("Traverse:\n");

  traverse(ht);
  init_table(ht);
  for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
    //element_t e;
    strcpy(e.key, keys[i]);
    strcpy(e.word, keys[i]);
    e.next = NULL;
    insertItem(ht, e);
  }
  printf("\n===========================================\n");
  printf("\nFind Lisa Smith: \n");
  p = findElement(ht, "Lisa Smith");
  printf("\n%s\n",p->key);
  printf("\n===========================================\n");
  printf("Clear Bucket 6: \n");
  clearbucket(ht,6);
  traverse(ht);
    init_table(ht);
  for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
    //element_t e;
    strcpy(e.key, keys[i]);
    strcpy(e.word, keys[i]);
    e.next = NULL;
    insertItem(ht, e);
  }
  printf("\n===========================================\n");
  printf("\nRemove Lisa Smith: \n");
  removeElement(ht,"Lisa Smith");
  traverse(ht);
  printf("\n===========================================\n");
  return 0;
}