#include"graph.h"
#include"stdio.h"
#include"stdlib.h"
void Dijkstra(Graph *g, int v){
		int vex_num = g->n;
		int set[vex_num];
		int dist[vex_num];
		int path[vex_num];
		int min, i,j, u;
		for (i = 0; i<vex_num; i++){
				dist[i] = g->edges[v][i];
				set[i] = 0;
				if(g->edges[v][i] < MAX_INT)
						path[i] = v;
				else
						path[i] = -1;
		}
		set[v] = 1;
		path[v] = -1;
		// 以上是所有参数的初始化，完成v，加入S集合
		for(i = 0 ; i < vex_num - 1; i++){
				min = MAX_INT;
				// 找到最小dist的加入集合S
				for(j = 0 ; j< vex_num; j++){
						if(set[j] == 0 && dist[j] < min){
								u = j;
								min = dist[j];
						}
				}
				set[u] = 1;
				// 以ｕ为中间点更新dist
				for(j = 0; j < vex_num; j++){
						if(set[j] == 0 && dist[u] + g->edges[u][j] < dist[j]){
								dist[j] = dist[u] + g->edges[u][j];
								path[j] = u;
						}
				}
		}
		// 打印数组，不属于算法本身
	printf("DIST ARRAY:\n");
	for(i = 0; i< vex_num; i++)
			printf("%2d ", dist[i]);
	printf("\nPATH ARRAY:\n");
	for(i = 0; i< vex_num; i++)
			printf("%2d ", path[i]);
	printf("\n");
}


int main(){
		Graph *g;
		g = (Graph *)malloc(sizeof(Graph));
		CreateGraph(g);
		Dijkstra(g, 0);
}
