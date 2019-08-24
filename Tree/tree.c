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

void preOrderNoRec(BiTree t) {
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

void inOrderNoRec(BiTree t) {
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

void postOrderNoRec(BiTree t) {
  BiTree stack[50];
  int top = -1;
  // 标记最后访问的结点
  BiTree lastVisit;
  while (t || top != -1) {
    // 一直遍历左子树
    if (t) {
      stack[++top] = t;
      t = t->lchild;
    } else {
      t = stack[top];
      // 右子树为空或者已经访问，则访问该节点，并且更新最后访问结点，跳出此次循环
      if (!t->rchild || t->rchild == lastVisit) {
        top--;
        visit(*t);
        lastVisit = t;
        t = 0;
        continue;
      }
      // 右子树存在且未访问则继续往右子树搜索
      t = t->rchild;
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

int treeDepth(BiTree t) {}