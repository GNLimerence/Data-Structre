#include <stdio.h>
#include "stack.h"
#include <string.h>
#define NUM_MAX 100000
stack_t Seperate(char str[NUM_MAX]){
    stack_t s;
    initialize(&s);
    for (int i = 0; str[i] != '\0';i++){
         push(str[i],&s);
    }
    return s;
}
int main(){
    stack_t interger1;
    stack_t interger2; 
    stack_t result;
    char str1[NUM_MAX];
    char str2[NUM_MAX];
    printf("Nhap vao so thu nhat: \n");
    scanf("%s",&str1);
    interger1 = Seperate(str1);
    printf("Nhap vao so thu hai: \n");
    scanf("%s",&str2);
    interger2 = Seperate(str2);
    int nho=0;
    int tong;
    int a = 0;
    int b = 0;
    while(!isEmpty(interger1)||!isEmpty(interger2)){
        if(!isEmpty(interger1)&&!isEmpty(interger2)){
            a = pop(&interger1);
            b = pop(&interger2);
            tong = a + b + nho;
            if (tong >= 10)
            {
                nho = 1;
                tong %= 10;
            }else{
                nho = 0;
            }
             pop(&interger1);
             pop(&interger2);
        }else if (!isEmpty(interger1)&&isEmpty(interger2)){
            a = pop(&interger1);
            tong = a + nho;
            if (tong >= 10)
            {
                nho = 1;
                tong %= 10;
            }else{
                nho = 0;
            }
             pop(&interger1);
        }else if (isEmpty(interger1)&&!isEmpty(interger2)){
            b = pop(&interger2);
            tong = b + nho;
            if (tong >= 10)
            {
                nho = 1;
                tong %= 10;
            }else {
                nho = 0;
            }
             pop(&interger2);
        }
       push(tong,&result);
        /*if (nho == 1)
        {
            result = push(result,nho);
        }*/
        while (!isEmpty(result))
        {
            showData(pop(&result));
        }
    }
    return 0;
}