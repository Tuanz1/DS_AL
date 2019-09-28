#ifndef _GRAPH_H
#define _GRAPH_H
/**
 * 图的邻接矩阵表示
 * */
// 使用int 定义顶点类型
// 最大整型会导致越界问题
// #define MAX_INT ((unsigned)(-1) >> 1
// 最大顶点数10
#define MAX_INT 99 
#define bool int
#define true 1
#define false 0
#define MAXSIZE 10
#define VertexType int
typedef struct Graph {
  int edges[MAXSIZE][MAXSIZE];
  // 定点数和边数
  int n, e;
  // 存放顶点信息
  VertexType vex[MAXSIZE];
} Graph;
// 测试用，构造一个图
void CreateGraph(Graph *g);
// 判断x与y之间是否有边
bool Adjacent(Graph *g, int x, int y);
// 列出图G与结点x邻接的边
void Neighbors(Graph *g, int x);
// 往图中插入结点x
bool InsertVertex(Graph g, int x);
// 删除结点x
bool DeleteVertex(Graph g, int x);
// 往图中插入边<x, y>
bool AddEdge(Graph g, int x, int y);
// 删除边<x, y>
bool RemoveEdge(Graph g, int x, int y);
// 求图中x的第一个邻接结点，有则返回顶点号，否则返回-1
int FirstNeighbor(Graph *g, int x);
// 返回除y之外顶点x的下一个邻接结点的顶点号
int NextNeighbor(Graph *g, int x, int y);

#endif
