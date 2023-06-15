/*
Pham Hoang Hai Nam
MSSV: 20215099
Ngay Hoan Thanh: 8/12/2022
Muc tieu: Cai dat binsearch voi phan data cua dslk co key la string
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
  char id[20];
  char name[32];
  int grade;
} student_t;
typedef struct node_s {
  student_t data;
  struct node_s *next;
} node_t, *root_t;
//====llistFunction=============================
void showData(student_t data);
root_t llPrint(root_t root);
node_t* createNewNode(const student_t data);
root_t llInsertStudent(root_t root, const student_t data);
root_t llDeleteAll(root_t root);
//==============================================
//====AddedFunction=============================
node_t *Posistion(root_t lst, int index); //find the posistion of the node
student_t *binarySearchByName(root_t lst, char *key); //using binary search with key = string(name)
//==============================================
root_t llInit() { return NULL; }
void showData(student_t data) { 
  printf("%s - %s - %d\n", data.id, data.name, data.grade);
}
root_t llPrint(root_t root) {
  for (node_t* p = root; p != NULL; p = p->next) showData(p->data);
  printf("\n");
  return root;
}
node_t* createNewNode(const student_t data) {
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if (newNode == NULL) return NULL;

  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}
root_t llInsertStudent(root_t root, const student_t data) {
  node_t* pNewNode = createNewNode(data);
  pNewNode->next = root;
  return (root_t)pNewNode;
}
root_t llDeleteAll(root_t root) {
  node_t* p = NULL;
  for (; root != NULL; root = p) {
    p = root->next;
    free(root);
  }
  return NULL;
}
node_t *Posistion(root_t lst, int index){
    int dem = 0;
    node_t *p = NULL;
    for (p = lst; p != NULL && dem != index; p = p->next){
        dem++;
    }if (dem == index && p != NULL){
        return p;
    }
    return NULL;
}
student_t *binarySearchByName(root_t lst, char *key){
    int low = 0;
    int length = 0;
    node_t *p = NULL;
    node_t *a = NULL;
    for (p = lst; p != NULL; p = p->next){
        ++length;
    }//find the length of the list
    int high = length - 1 ;
    int mid = (low + high) / 2;
    for (;low <= high; mid = (low + high) / 2){
        a = Posistion(lst,mid);
        if (strcmp(a->data.name,key) == 0)
            return (student_t*)a;
        else if (strcmp(a->data.name,key) > 0)
            high = mid - 1;
        else
            low = mid + 1;        
    }
    return NULL;  
}
int main (){
  student_t aSV[] ={{"001", "E", 6},
                    {"002", "D", 7},
                    {"003", "C", 8},
                    {"004", "B", 9},
                    {"005", "A", 10}};
    root_t lst = llInit();
    for (int i = 0; i < sizeof(aSV)/sizeof(aSV[0]); i++){
        lst = llInsertStudent(lst, aSV[i]);
    }
    printf("The Student List:\n");
    llPrint(lst);
    printf("Find the student by name:\n");
    student_t *pstudent = binarySearchByName(lst, "A");
    if (pstudent == NULL)printf("Khong Tim Thay. \n");
    else showData(*pstudent);
    lst = llDeleteAll(lst);
    return 0;
}
