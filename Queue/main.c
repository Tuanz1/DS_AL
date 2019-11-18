#include "queue.h"
#include "stdio.h"
int main() {
  int t = 5;
  Queue *q;
  q = InitQueue(6);
  for (int i = 0; i < t; i++) {
    EnQueue(q, i);
  }
  for (int i = 0; i < t; i++)
    printf("%d", DeQueue(q));
}