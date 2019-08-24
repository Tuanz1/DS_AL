#include "stdio.h"
#include "tree.h"

int main() {
  BiTree t;
  createTree(&t);
  printf("前序遍历\n");
  preOrder(t);
  printf("\n中顺遍历\n");
  inOrder(t);
  printf("\n后顺遍历\n");
  postOrder(t);
  printf("\n非递归前序遍历\n");
  preOrderNoRec(t);
  printf("\n非递归中序遍历\n");
  inOrderNoRec(t);
  printf("\n非递归后序遍历\n");
  postOrderNoRec(t);
  printf("\n层次遍历\n");
  levelOrder(t);
}