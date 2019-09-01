#ifndef _TREE_H
#define _TREE_H
#define ElementType int
#define MAXSIZE 50
#define bool int
#define true 1
#define false 0

typedef struct BiNode {
  ElementType data;
  struct BiNode *lchild, *rchild;
} BiNode, *BiTree;
// 非递归需构造一个栈的数据结构

// 构造二叉树
void createTree(BiTree *t);
// 构造二叉树过程中使用的插入结点函数
// 访问结点内容
void visit(BiNode node);
// 三种顺序的遍历算法
void preOrder(BiTree t);
void inOrder(BiTree t);
void postOrder(BiTree t);

// 层次遍历
void levelOrder(BiTree t);
int treeDepth(BiTree t);
// 递归计算叶子结点数
int countLeaves(BiTree t);
#endif