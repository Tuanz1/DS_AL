// 二分图最大匹配
#include "graph.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
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
  int out[g->n];
  for(int i =0;i<g->n;i++){
		  if(!visit[i]){
				  visit[i]=1;
				  visit[match[i]] = 1;
		  		  int index = i/5;
		  		  int offset = match[i]%5+1;
		  if(index==1)
		  printf("X%d--Y%d\n",i%5+1, offset);
		 else 
				 printf("Y%d--X%d\n",i%5+1,offset);
		  }
  }
}
