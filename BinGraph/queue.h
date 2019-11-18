#ifndef _QUEUE_H
#define _QUEUE_H
#include "stdlib.h"
typedef struct {
  int front, rear;
  int size;
  int *data;
} Queue;
// 初始化一个size大小的队列
Queue *InitQueue(int size);
int isEmpty(Queue *q);
int isFull(Queue *q);
int EnQueue(Queue *q, int x);
int DeQueue(Queue *q);
#endif