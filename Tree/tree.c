#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
// 为了使传值和传参，此处使用BiTree * 相当于BiNode **
// 来是ｔ指针内容修改，而不是传值，此处要注意
void createTree(BiTree *t) {
  printf("开始创建树，0代表NULL  \n");
  int data;
  printf("输入结点数据：\n");
  scanf("%d", &data);
  if (data == 0) {
    *t = NULL;
  } else {
    *t = (BiTree)malloc(sizeof(BiNode));
    (*t)->data = data;
    printf("继续创建当前结点%d左子树\n", data);
    createTree(&((*t)->lchild));
    printf("继续创建当前结点%d右子树\n", data);
    createTree(&((*t)->rchild));
  }
}

void visit(BiNode node) { printf("%d  ", node.data); }
void preOrder(BiTree t) {
  if (t != NULL) {
    visit(*t);
    preOrder(t->lchild);
    preOrder(t->rchild);
  }
}

void inOrder(BiTree t) {
  if (t != NULL) {
    inOrder(t->lchild);
    visit(*t);
    inOrder(t->rchild);
  }
}

void postOrder(BiTree t) {
  if (t != NULL) {
    postOrder(t->lchild);
    postOrder(t->rchild);
    visit(*t);
  }
}

void levelOrder(BiTree t) {
  BiTree queue[50];
  int front = 0, rear = 0;
  queue[rear++] = t;
  while (front != rear) {
    t = queue[front++];
    visit(*t);
    if (t->lchild)
      queue[rear++] = t->lchild;
    if (t->rchild)
      queue[rear++] = t->rchild;
  }
}

int treeDepth(BiTree t) {
  if (t == NULL)
    return 0;
  if (t->lchild == NULL && t->rchild == NULL) {
    return 1;
  } else {
    int l, r;
    l = treeDepth(t->lchild);
    r = treeDepth(t->rchild);
    return l > r ? 1 + l : 1 + r;
  }
}

int countLeaves(BiTree t) {
  if (!t)
    return 0;
  if (t->lchild == NULL && t->rchild == NULL)
    return 1;
  int l = countLeaves(t->lchild);
  int r = countLeaves(t->rchild);
  return l + r;
}