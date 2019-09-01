#ifndef _HFM_H
#define _HFM_H

//哈弗曼树结点
typedef struct TreeNode {
  char code;
  int weight;
  struct TreeNode *lchild, *rchild;
} TreeNode;

// 哈弗曼队列结点
typedef struct LinkedNode {
  char code;
  int weight;
  struct LinkedNode *next;
  // 字符对应的树中结点
  struct TreeNode *node;
} LinkedNode;

// 输入字符以及对应的权重，按照权重构造递增队列
LinkedNode *input();
// 往队列中插入结点，并且保证队列依然递增
void inQueue(LinkedNode *head, LinkedNode *node);
// 遍历队列，检查是否递增
void traverse(LinkedNode *head);
// 构造哈弗曼树
void createHFMTree();
//  输出每个字符对应的哈弗曼编码
void hfmCode(TreeNode *tree, int length);
#endif
