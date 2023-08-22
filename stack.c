#include "stack.h"
#include <stdlib.h>

void initialize(stack_t *pStack) { (*pStack).top = 0; }

int isEmpty(stack_t stack) { return stack.top == 0; }

int isFull(stack_t stack) { return stack.top == MAX; }

void push(elem_t el, stack_t *pStack) {
  if (isFull(*pStack)) {
    printf("Stack overflow\n");
    exit(EXIT_STACK_OVERFLOW);
  } else
    (*pStack).storage[(*pStack).top++] = el;
}

elem_t pop(stack_t *pStack) {
  if (isEmpty(*pStack)) {
    printf("stack underflow");
    exit(EXIT_STACK_UNDERFLOW);
  } else
    return (*pStack).storage[--(*pStack).top];
}