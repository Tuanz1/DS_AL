#include "queue.h"
Queue *InitQueue(int size) {
  Queue *q;
  q = (Queue *)malloc(sizeof(Queue));
  q->size = size;
  q->data = (int *)malloc(size * sizeof(int));
  q->front = 0;
  q->rear = 0;
  return q;
  // 不判断错误
}
int isEmpty(Queue *q) {
  if (q->front == q->rear)
    return 1;
  return 0;
}
int isFull(Queue *q) {
  if ((q->rear + 1) % q->size == q->front)
    return 1;
  return 0;
}
int EnQueue(Queue *q, int x) {
  if (!isFull(q)) {
    q->rear = (q->rear + 1) % q->size;
    q->data[q->rear] = x;
    return 1;
  }
  return 0;
}
int DeQueue(Queue *q) {
  if (!isEmpty(q)) {
    q->front = (q->front + 1) % q->size;
    return q->data[q->front];
  }
  return -1;
}