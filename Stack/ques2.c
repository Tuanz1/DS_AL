#include "stack.h"
#include "stdio.h"
int p_rec(int x, int n) {
  if (n == 0)
    return 1;
  if (n == 1)
    return 2 * x;
  else
    return 2 * x * p_rec(x, n - 1) - 2 * (n - 1) * p_rec(x, n - 2);
}
int p(int x, int n) {
  int p_n, p_n1, p_n2;
  if (n == 0)
    return 1;
  if (n == 1)
    return 2 * x;
  Stack *stack;
  stack = initStack();
  push(stack, 1);
  push(stack, 2 * x);
  for (int i = 1; i < n; i++) {
    p_n1 = getTop(stack);
    p_n2 = stack->data[stack->top - 1];
    // 这里ｎ和ｉ的关系很微妙，使用递推公式的ｎ要转化为循环的ｉ，否则会出现错误
    p_n = 2 * x * p_n1 - 2 * i * p_n2;
    push(stack, p_n);
  }
  return getTop(stack);
}
int main() {
  int x = p_rec(1, 5);
  printf("X:%d\n", x);
  int y = p(1, 5);
  printf("Y:%d\n", y);
}