#include "hash.h"

#include <string.h>

element_t *D[TABLE_SIZE];  // <===

// Hash Code Maps
// Component Sum
static const int transform(const char *key) {
  int number;
  for (number = 0; (*key) != 0; key++) number += *key;
  return number;
}

// Compression map
int hash(const char *key) { return (transform(key) % TABLE_SIZE); }

// ====================================
//
// ====================================

void init_table(element_t *ht[]) {  // <===
  clear(ht);
}

void clear(element_t *ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    clearbucket(ht, i);
  }
}

void clearbucket(element_t *ht[], int b) {
  // your code here
  element_t *p;
  element_t *q;
  q = NULL;
  p = ht[b];
  while (p != NULL){
    q = p;
    p = p->next;
    free (q);
  }
  ht[b] = NULL;
}

element_t *findElement(element_t *ht[], char key[]) {
  const int hash_value = hash(key);
  if (ht[hash_value] == NULL)
    return NULL;
  else{  // Traverse through the list at bucket H(X)
    // your code here
    ht[hash_value];
    for (;ht[hash_value] != NULL;ht[hash_value] = ht[hash_value]->next)
    {
      if (strcmp(ht[hash_value]->key,key) == 0) return ht[hash_value];
    }
  }
  return NULL;
}

int insertItem(element_t *ht[], element_t o) {
  int hash_value = hash(o.key);
  element_t *p;
  element_t *pNewElement = (element_t *)malloc(sizeof(element_t) * 1);
  strcpy(pNewElement->key, o.key);
  strcpy(pNewElement->word, o.word);
  pNewElement->next = NULL;

  if (ht[hash_value] == NULL) {
    ht[hash_value] = pNewElement;
    return TRUE;
  } else {
    // your code here
    p = ht[hash_value];
    ht[hash_value] = (element_t *)malloc(sizeof(element_t));
    strcpy(ht[hash_value]->key,o.key);
    ht[hash_value]->next = p;
    return TRUE;
  }
}

int removeElement(element_t *ht[], char key[]) {
  int hash_value = hash(key);
  int count;
  element_t *p1 = ht[hash_value];
  element_t *q;
  element_t *p;
  if ( p1 == NULL)
    return -1;  // khong tim thay
  else{
    // your code here
    if(strcmp(p1->key,key) == 0){
      q = p1;
      p1 = p1->next;
      free(q);
      //ht[hash_value] = NULL;
    }else{
      count = 0;
      p = p1;
    while((p->next != NULL) && (!count)){
        if(strcmp(p->next->key,key) == 0){
            count = 1;
        }else p = p->next;
      }
      if (count){
          q = p->next;
          p->next = q->next;
          free(q);
         
      }
    }
  }
}
int isEmpty(element_t *ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++)
    if (ht[i] != NULL) return FALSE;
  return TRUE;
};
void traverse(element_t *ht[]) {
  for (int b = 0; b < TABLE_SIZE; b++) {
    printf("\nBucket %d\n", b);
    _traversebucket(ht, b);
  }
}
void _traversebucket(element_t *ht[], int b) {
  // your code here
  while (ht[b] != NULL){
    printf("---%s",ht[b]->key);
    ht[b] = ht[b]->next;
  }
}