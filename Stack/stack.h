/**
stack.h　ｃ语言栈（只定义最基础的栈操作）

**/
#ifndef _STACK_H
#define _STACK_H
// 定义一些bool值
#define bool int
#define true 1
#define false 0
// 定义栈的某些数据
#define ElementType int
#define MAXSIZE 50
typedef struct {
  ElementType data[MAXSIZE];
  int top;
} Stack;

Stack * initStack();
bool isStackEmpty(Stack *stack);
bool isStackFull(Stack *stack);
bool push(Stack *stack, ElementType e);
ElementType pop(Stack *stack);
ElementType getTop(Stack *stack);
#endif
