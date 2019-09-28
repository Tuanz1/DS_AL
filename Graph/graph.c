#include "graph.h"
#include <stdio.h>

void CreateGraph(Graph *g) {
  int n, e = 0;
  int tmp;
  //   printf("请输出顶点数n\n");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      //   printf("请输入边<%d, %d>的值(-1则赋值最大值)\n", i, j);
      scanf("%d", &tmp);
      if (tmp == -1)
        g->edges[i][j] = MAX_INT;
      else {
        g->edges[i][j] = tmp;
        e++;
      }
    }
  }
  //   printf("共输入%d条边\n", e);
  g->n = n;
  g->e = e;
}

// 判断x与y之间是否有边
bool Adjacent(Graph *g, int x, int y) {
  if (g->edges[x][y] > 0 && g->edges[x][y] < MAX_INT)
    return true;
  return false;
}
// 列出图G与结点x邻接的边
void Neighbors(Graph *g, int x) {
  if (0 > x || x > g->n) {
    printf("没有此结点\n");
    return;
  }
  printf("与结点%d相连的结点有:", x);
  for (int i = 0; i < g->n; i++) {
    if (g->edges[x][i] != MAX_INT) {
      printf("%d;", i);
    }
  }
  printf("\n");
}
// 删除边，加点啥的基本的东西不实现,没啥难度
// 求图中x的第一个邻接结点，有则返回顶点号，否则返回-1
int FirstNeighbor(Graph *g, int x) {
  if (x < 0 || x > g->n)
    return -1;
  for (int i = 0; i < g->n; i++)
    if (g->edges[x][i] != MAX_INT)
      return i;
  return -1;
}
// 返回除y之外顶点x的下一个邻接结点的顶点号
int NextNeighbor(Graph *g, int x, int y) {
  if (x < 0 || x > g->n)
    return -1;
  for (int i = y + 1; i < g->n; i++)
    if (g->edges[x][i] != MAX_INT)
      return i;
  return -1;
}
