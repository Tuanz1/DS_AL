#include "stack.h"
#include "stdio.h"
#include "stdlib.h"

Stack *initStack() {
  Stack *stack;
  stack = (Stack *)malloc(sizeof(Stack));
  if (!stack) {
    printf("无法分配储存空间");
    return NULL;
  }
  stack->top = -1;
  return stack;
}

bool isStackEmpty(Stack *stack) {
  if (stack->top == -1)
    return true;
  return false;
}

bool isStackFull(Stack *stack) {
  if (stack->top == MAXSIZE)
    return true;
  return false;
}

bool push(Stack *stack, ElementType e) {
  if (!isStackFull(stack)) {
    stack->data[++stack->top] = e;
    return true;
  }
  return false;
}

ElementType pop(Stack *stack) {
  //   if (!isStackEmpty) {
  return stack->data[stack->top--];
  //   }
  //   return NULL;
}

ElementType getTop(Stack *stack) { return stack->data[stack->top]; }
