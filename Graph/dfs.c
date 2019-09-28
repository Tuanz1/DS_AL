#include"graph.h"
#include"stdio.h"
#include"stdlib.h"

// 递归实现DFS算法
void DFS(Graph *g, int i, int visit[]){
	printf("Visit:%d\n", i);
	visit[i] = true;
	for(int j = FirstNeighbor(g, i); j >= 0; j = NextNeighbor(g, i,	j)){
			if(!visit[j])
				DFS(g, j, visit);
	}
}
// 对于非联通图，需要这一步才能遍历所有联通分量
void DFSTraverse(Graph *g){
		int visit[g->n];
		for(int i = 0; i< g->n; i++)
				visit[i] = false;
		for(int i = 0 ; i< g->n; i++){
				if (!visit[i])
						DFS(g, i, visit);
		}
}

int main(){
		Graph *g;
		g = (Graph *)malloc(sizeof(Graph));
		CreateGraph(g);
		DFSTraverse(g);
}

