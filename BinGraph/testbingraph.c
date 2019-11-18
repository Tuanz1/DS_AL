// 二分图相关算法　二分图验证和最匈牙利算法
#include "graph.h"
#include "queue.h"
#include "stdio.h"
#include <stdlib.h>
// 颜色数组　-1 为未染色  0 黑　１白
int color[MAX_INT];
// 验证ｇ是否是二分图
bool bfs(Graph *g, int index) {
  //该点染黑
  color[index] = 1;
  Queue *q = InitQueue(g->n + 1);
  EnQueue(q, index);
  while (!isEmpty(q)) {
    int from = DeQueue(q);
    for (int i = 0; i < g->n; i++) {
      if (g->edges[from][i] && color[i] == -1) {
        color[i] = !color[from];
        8 EnQueue(q, i);
      }
      if (color[from] == color[i] && g->edges[from][i])
        return false;
    }
  }
  return true;
}
int main() {
  Graph *g;
  bool flag = false;
  g = (Graph *)malloc(sizeof(Graph));
  CreateGraph(g);
  for (int i = 0; i < g->n; i++) {
    color[i] = -1;
  } // 这个不是化是会出问题的
  for (int i = 0; i < g->n; i++) {
    if (color[i] == -1 && !bfs(g, i)) {
      flag = true;
      break;
    }
  }
  if (flag)
    printf("不是二分图\n");
  else
    printf("是二分图\n");
}