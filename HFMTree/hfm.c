#include "hfm.h"
#include <stdio.h>
#include <stdlib.h>

LinkedNode *input() {
  LinkedNode *head;
  head = (LinkedNode *)malloc(sizeof(LinkedNode));
  head->next = NULL;
  head->weight = 0;

  while (1) {
    // printf("输入字符\n");
    char code;
    scanf("%c", &code);
    // printf("输入字符%c对应的权重(如果为0则结束输入!)\n", code);
    int weight;
    scanf("%d", &weight);
    if (weight == 0)
      break;
    LinkedNode *newNode;
    newNode = (LinkedNode *)malloc(sizeof(LinkedNode));
    newNode->code = code;
    newNode->weight = weight;
    inQueue(head, newNode);
  }
  return head;
}

void inQueue(LinkedNode *head, LinkedNode *node) {
  LinkedNode *tmp;
  tmp = head;
  while (tmp->next != NULL) {
    if (tmp->next->weight < node->weight)
      tmp = tmp->next;
    else
      break;
  }
  node->next = tmp->next;
  tmp->next = node;
}

LinkedNode *deQueue(LinkedNode *head) {
  LinkedNode *tmp;
  tmp = head->next;
  head->next = tmp->next;
  return tmp;
}

void traverse(LinkedNode *head) {
  LinkedNode *tmp;
  tmp = head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
    printf("Char:%c, Weight:%d\n", tmp->code, tmp->weight);
  }
}
TreeNode *createTreeNode(char code, int weight, TreeNode *left,
                         TreeNode *right) {
  TreeNode *node;
  node = (TreeNode *)malloc(sizeof(TreeNode));
  node->code = code;
  node->weight = weight;
  node->lchild = left;
  node->rchild = right;
  return node;
}
TreeNode *createHFMTree(LinkedNode *head) {
  LinkedNode *tmp;
  tmp = head;
  LinkedNode *p, *q;
  TreeNode *root, *node;
  // 队列长度大于二时开始编码，队列长度为1时说明为根结点
  while (head->next && head->next->next) {
    // 取出队列中权重最小的元素
    p = deQueue(head);
    q = deQueue(head);
    // 如果p, q 为叶子结点，则需要为期构造node
    if (p->code != ' ') {
      p->node = createTreeNode(p->code, p->weight, NULL, NULL);
    }
    if (q->code != ' ') {
      q->node = createTreeNode(q->code, q->weight, NULL, NULL);
    }
    // 构造p, q 的根结点，并且将新构造的root结点入队
    root = createTreeNode(' ', p->weight + q->weight, p->node, q->node);
    tmp = (LinkedNode *)malloc(sizeof(LinkedNode));
    tmp->code = ' ';
    tmp->weight = root->weight;
    tmp->node = root;
    free(p);
    free(q);
    inQueue(head, tmp);
  }
  return root;
}
// 先序遍历哈弗曼树
// void preOrder(TreeNode *tree) {
//   if (tree != NULL) {
//     printf("Char:%c, Weight:%d\n", tree->code, tree->weight);
//     preOrder(tree->lchild);
//     preOrder(tree->rchild);
//   }
// }
void hfmCode(TreeNode *tree, int length) {
  // 哈弗曼编码最长为10,
  // 一定要是静态数组，相当于全局数组变量，否则每次都执行一次初始化，就全是0了
  static int a[10];
  // 为叶子结点，则输出对应哈弗曼编码
  if (!tree->lchild && !tree->rchild) {
    printf("Char:%c", tree->code);
    for (int i = 0; i < length; i++)
      printf("%d", a[i]);
    printf("\n");
  }
  // 否则修改对应的a[length]，然后递归下一层
  else {
    a[length] = 0;
    hfmCode(tree->lchild, length + 1);
    a[length] = 1;
    hfmCode(tree->rchild, length + 1);
  }
}
int main() {
  LinkedNode *head;
  head = input();
  //   traverse(head);
  TreeNode *root;
  root = createHFMTree(head);
  hfmCode(root, 0);
  //   preOrder(root);
}
