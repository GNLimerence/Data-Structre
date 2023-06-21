#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "../libSearch.h"

#define NOT_FOUND (-1)
#define MAX_SIZE (100)

typedef char T;
typedef char key_T;

enum { FALSE = 0, TRUE };

// M: Array to search
// N: number of element in M
// T: type // typedef int T
int linearSearch(T a[], const int n, const key_T key) {
  int i = 0;
  while (a[i] != key && i < n) i++;
  if (i < n) return (i);
  return (NOT_FOUND);
}

// compare two unordered lists list1 and list2
// n: length of lst1
// m: length of lst2
void verify1(T lst1[], T lst2[], int n, int m) {
  int marked[MAX_SIZE];

  for (int i = 0; i < m; i++) marked[i] = FALSE;

  int j;
  for (int i = 0; i < n; i++)
    if ((j = linearSearch(lst2, m, lst1[i])) == NOT_FOUND)
      printf("%c is not in list2\n ", lst1[i]);
    else
      marked[j] = TRUE;  // check each of the other fields from list1[i] and
                         // list2[j], and print out any discrepancies

  for (int i = 0; i < m; i++)
    if (!marked[i]) printf("%c is not in list1\n", lst2[i]);
}

int main() {
  char lst1[] = "abcdefghijk";
  char lst2[] = "aceijz";
  verify1(lst1, lst2, strlen(lst1), strlen(lst2));
  return 0;
}