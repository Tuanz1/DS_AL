#include"graph.h"
#include"stdio.h"
#include"stdlib.h"

// 实现BFS算法,需要一个队列辅助
void BFS(Graph *g, int i, int visit[]){
	printf("Visit:%d\n", i);
	visit[i] = true;
	int queue[g->n];
	int front = 0, rear =0;
	queue[rear++] = i;
	while(front!=rear){//队列内容不为空
			i = queue[front++];// 出队，然后遍历所有ｉ的邻接点
			for(int j = FirstNeighbor(g, i); j >= 0; j = NextNeighbor(g, i,	j)){
				if(!visit[j]){
					printf("Visit:%d\n", j);
					visit[j] = true;
					queue[rear++] = j;
				}
			}
	}
}
// 对于非联通图，需要这一步才能遍历所有联通分量
void BFSTraverse(Graph *g){
		int visit[g->n];
		for(int i = 0; i< g->n; i++)
				visit[i] = false;
		for(int i = 0 ; i< g->n; i++){
				if (!visit[i])
					BFS(g, i, visit);
		}
}

int main(){
		Graph *g;
		g = (Graph *)malloc(sizeof(Graph));
		CreateGraph(g);
		BFSTraverse(g);
}
