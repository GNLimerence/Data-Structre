/*Pham Hoang Hai Nam
20215099
Ngay hoan thanh: 7/12/2022
Muc tieu: so sanh 2 danh sach
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE (100)
enum { FALSE = 0, TRUE };
typedef struct phoneAddr_s {
  char name[20];
  char tel[20];
  char email[32];
} phoneAddr_t;               
int linearSearch(phoneAddr_t items[], int siz, char key[]) {
  for (int i = 0; i < siz; i++){
    if (strcmp(items[i].name,key)==0){ 
        return i;
    }
}
return -1;  // no match
}
void verify1(phoneAddr_t lst1[], phoneAddr_t lst2[], int n, int m) {
  int marked[MAX_SIZE];

  for (int i = 0; i < m; i++) marked[i] = FALSE;

  int j;
  for (int i = 0; i < n; i++)
    if ((j = linearSearch(lst2, m, lst1[i].name)) == -1)
      printf("%s %s %s is not in list2\n ", lst1[i].name,lst1[i].tel,lst1[i].email);
    else
      marked[j] = TRUE;  // check each of the other fields from list1[i] and
                         // list2[j], and print out any discrepancies

  for (int i = 0; i < m; i++)
    if (!marked[i]) 
        printf("%s %s %s is not in list1\n ", lst2[i].name,lst2[i].tel,lst2[i].email);
}
void verify2(phoneAddr_t lst1[], phoneAddr_t lst2[], int n, int m){
   int index1, index2;
   for (int i = 0; i < n; i++){
    if (index2 = linearSearch(lst2, m, lst1[i].name) != -1){
      printf("%s %s %s from list 1\n",lst1[i].name,lst1[i].tel,lst1[i].email); 
   }
   }     
   for (int j = 0; j < m; j++){
    if (index1 = linearSearch(lst1, n, lst2[j].name) != -1){
      printf("%s %s %s from list 2\n",lst2[j].name,lst2[j].tel,lst2[j].email);
   }
   } 
}
int main() {
phoneAddr_t lst1[] = {{"A", "1", "1@"},
                      {"E", "3", "3@"},
                      {"K", "4", "4@"},
                      {"D", "5", "5@"}};
phoneAddr_t lst2[] = {{"A", "7", "8@"},
                      {"F", "2", "2@"},
                      {"C", "3", "3@"},
                      {"D", "4", "4@"}};  
  printf("Different Element: \n");
  verify1(lst1, lst2, sizeof(lst1)/sizeof(lst1[0]), sizeof(lst2)/sizeof(lst2[0]));
  printf("Same Element: \n");
  verify2(lst1, lst2, sizeof(lst1)/sizeof(lst1[0]), sizeof(lst2)/sizeof(lst2[0]));
  return 0;
}