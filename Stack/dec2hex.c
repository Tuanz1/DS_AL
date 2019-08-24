#include "stack.h"
#include "stdio.h"

void dec2hex(int i) {
  char zero = '0';
  Stack *stack;
  stack = initStack();
  int d = 1;
  while (i != 0) {
    d = i % 16;
    i = i / 16;
    switch (d) {
    case 10:
      push(stack, 'A');
      break;
    case 11:
      push(stack, 'B');
      break;
    case 12:
      push(stack, 'C');
      break;
    case 13:
      push(stack, 'D');
      break;
    case 14:
      push(stack, 'E');
      break;
    case 15:
      push(stack, 'F');
      break;
    default:
      push(stack, zero + d);
      break;
    }
  }
  while (!isStackEmpty(stack)) {
    char hex = pop(stack);
    printf("%c", hex);
  }
  printf("\n");
}
int main() { dec2hex(100); }
