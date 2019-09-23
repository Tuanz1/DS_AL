/*
 * tree.h 的非递归实现
 * 其中visit createTree levelOrder与tree.c 文件中相同，这些函数不存在递归不递归
 */
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
  BiTree stack[50];
  int top = -1;
  while (t || top != -1) {
    if (t) {
      visit(*t);
      stack[++top] = t;
      t = t->lchild;
    } else {
      t = stack[top--]->rchild;
    }
  }
}

void inOrder(BiTree t) {
  BiTree stack[50];
  int top = -1;
  while (t || top != -1) {
    if (t) {
      stack[++top] = t;
      t = t->lchild;
    } else {
      t = stack[top--];
      visit(*t);
      t = t->rchild;
    }
  }
}

void postOrder(BiTree t) {
  BiTree stack[50];
  int top = -1;
  BiTree p;
  p = t;
  // 标记最后访问的结点
  BiTree lastVisit;
  while (p || top != -1) {
    // 一直遍历左子树
    if (p) {
      stack[++top] = p;
      p = p->lchild;
    } else {
      p = stack[top];
      // 右子树为空或者已经访问，则访问该节点，并且更新最后访问结点，跳出此次循环
      if (!p->rchild || p->rchild == lastVisit) {
        top--;
        visit(*p);
        lastVisit = p;
        p = 0;
        continue; // 如果访问该节点，则说明，它之后的结点已经访问，不要遍历右子树，直接下一个循环
      }
      // 右子树存在且未访问则继续往右子树搜索
      p = p->rchild;
    }
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
// 第一种原理为非递归后续遍历，栈的最大深度+1  = 树的深度
// 第二种可以借助层次遍历，记录层数即可
int treeDepth(BiTree t) {
  int depth = 0;
  BiTree stack[50];
  int top = -1;
  // 标记最后访问的结点
  BiTree lastVisit;
  while (t || top != -1) {
    // 一直遍历左子树
    if (t) {
      stack[++top] = t;
      if (top + 1 > depth)
        depth = top + 1;
      t = t->lchild;
    } else {
      t = stack[top];
      // 右子树为空或者已经访问，则访问该节点，并且更新最后访问结点，跳出此次循环
      if (!t->rchild || t->rchild == lastVisit) {
        top--;
        // visit(*t);
        if (top + 1 > depth)
          depth = top + 1;
        lastVisit = t;
        t = 0;
        continue;
      }
      // 右子树存在且未访问则继续往右子树搜索
      t = t->rchild;
    }
  }
  return depth;
}