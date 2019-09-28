#include"graph.h"
#include<stdio.h>
#include<stdlib.h>

void floyd(Graph *g){
	int num_vex = g->n;
	int path[num_vex][num_vex];
	int dist[num_vex][num_vex];
	// 复制邻接矩阵到dist数组
	for(int i = 0; i< num_vex; i++){
			for(int j = 0; j<num_vex;j++){
					dist[i][j] = g->edges[i][j];
					// 路径全部设置为-1
					path[i][j] = -1;
			}
	}//for

	// 最关键的部分是最外层的for循环变量作为中间量
	for(int i = 0; i < num_vex; i++)
			for(int j = 0; j <num_vex;j++)
					for(int k = 0; k < num_vex; k++){
							if(dist[j][i] + dist[i][k] < dist[j][k]){
									dist[j][k] = dist[j][i] + dist[i][k];
									path[j][k] = i;
							}
					}
	// 打印结果，这部分不属于算法本身
	printf("Dist Array\n");
	for(int i = 0; i<num_vex; i++){
			for(int j = 0; j < num_vex; j++){
					printf("%2d ", dist[i][j]);
			}
			printf("\n");
	}
	printf("Path Array\n");
	for(int i = 0; i<num_vex; i++){
	for(int j = 0; j < num_vex; j++){
			printf("%2d ", path[i][j]);
			}
			printf("\n");
	}
}

int main(){
		Graph *g;
		g = (Graph *)malloc(sizeof(Graph));
		CreateGraph(g);
		floyd(g);
}
