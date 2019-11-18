// 二分图最大匹配
#include "graph.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
// cx 左边　cy右边
int cx[MAX_INT], cy[MAX_INT];
int visit[MAX_INT];
int match[MAX_INT];
bool dfs(Graph *g, int x) {
  for (int i = 0; i < g->n; i++) {
    if (g->edges[x][i]) {
      // 如果已经访问过，则直接下一个
      if (visit[i])
        continue;
      visit[i] = 1;
      if (match[i] == -1 || dfs(g, match[i])) {
        match[i] = x;
		match[x] = i;
        return true;
      }
    }
  }
  return false;
}
int maxmatch(Graph *g) {
  int res = 0;
  for (int i = 0; i < g->n; i++) {
    match[i] = -1;
  }
  for (int i = 0; i < g->n; i++) {
    for (int j = 0; j < g->n; j++)
      visit[j] = 0; //重置visit数组
    if (dfs(g, i))
      res++;
  }
  return res;
}
int main() {
  Graph *g;
  g = (Graph *)malloc(sizeof(Graph));
  CreateGraph(g);
  printf("最大匹配数为:%d\n", maxmatch(g));
}
