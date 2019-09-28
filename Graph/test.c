#include "graph.h"
#include "stdio.h"
#include "stdlib.h"

int main() {
  Graph *g;
  g = (Graph *)malloc(sizeof(Graph));
  CreateGraph(g);
  printf("%d\n", Adjacent(g, 0, 2));
  printf("%d\n", Adjacent(g, 2, 5));
  Neighbors(g, 5);
  printf("%d\n", FirstNeighbor(g, 2));
  printf("%d\n", NextNeighbor(g, 2, 4));
}
