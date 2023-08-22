/*
Ho ten sv: Pham Hoang Hai Nam.
MSSV:20215099
Ngay hoan thanh: 18/11/2022
Muc tieu: Ðao nguoc string bang stack.
*/
#include <stdio.h>
#include <string.h>
#include "stack.h"
int main() {
  char str[100];
  printf("Nhap vao chuoi:\n");
  scanf("%s",&str);
  stack_t s;
  initialize(&s);
  printf("Tach du lieu vao stack:\n");
  for (int i = 0; str[i]!='\0'; i++)push(str[i],&s);
  while (!isEmpty(s)) {
    showData(pop(&s));
  }
  return 0;
}
