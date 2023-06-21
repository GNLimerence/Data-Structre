#include <stdio.h>
#define NOT_FOUND (-1)
typedef int T;

int binarySearch(T a[], const T key, int low, int high) {
  if (low > high)return NOT_FOUND;
  int mid = (low + high) / 2;
    if (a[mid] < key)
      return binarySearch(a,key,low,mid-1);
    else if (a[mid] > key) 
      return binarySearch(a,key,mid + 1,high);
    else
      return mid;
  return NOT_FOUND; /* NotFound is defined as -1 */
}

int main() {
  int a[] = {15, 13, 9, 7, 5, 3, 1};
  for (int i = 20; i > 0; i--) {
    printf("BinarySearch of %d returns %d\n", i,
           binarySearch(a,i,0,sizeof(a) / sizeof(a[0])-1));
  }
  return 0;
}