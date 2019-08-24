#include "stack.h"
#include "stdio.h"

Stack *stack, *min_stack;

// 栈的判满什么省略
void stack_push(ElementType e) {
  if (isStackEmpty(min_stack))
    push(min_stack, e);
  else {
    ElementType min = min_stack->data[min_stack->top];
    min_stack->data[++min_stack->top] = (min < e) ? min : e;
  }
  stack->data[++stack->top] = e;
}

// 判空省略
ElementType stack_pop() {
  pop(min_stack);
  return pop(stack);
}

ElementType stack_min() { return getTop(min_stack); }

int main() {
  stack = initStack();
  min_stack = initStack();
  printf("测试三个函数:\n");
  stack_push(250);
  stack_push(20);
  stack_push(14);
  stack_push(15);
  stack_push(18);
  printf("min:%d\n", stack_min());
  stack_pop();
  printf("min:%d\n", stack_min());
}
