/**
 * 二叉树数据结构
 **/
#include "stdio.h"
#include "stdlib.h"
typedef struct BiTNode {
		int data;
		struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTree root;
// 先序地柜遍历二叉树
void PreOrder(BiTree T);
// 中序递归遍历二叉树
void InOrder(BiTree T);

// 后序递归遍历二叉树
void PostOrder(BiTree T);
// 求二叉树高度
int TreeHeight(BiTree T);
// 求二叉树的叶子节点个数
int LeafCount(BiTree T);
// 构造一个二叉树，已经有数据
void InitBiTree(BiTree T);
int main(){
		root  = (BiTNode *) malloc(sizeof(BiTNode));
		root->data = 1;
		BiTNode *cur = root;
		for (int i = 0; i < 5; i++){
				BiTNode *tmp = (BiTNode *)malloc(sizeof(BiTNode));
				tmp->data = i;
				cur->lchild = tmp;
				cur=tmp;
		}
		cur = root;
		for (int i = 0; i < 5; i++){
				BiTNode *tmp = (BiTNode *)malloc(sizeof(BiTNode));
				tmp->data = i;
				cur->rchild = tmp;
				cur=tmp;
		}
		InOrder(root);
		printf("\n");
		PostOrder(root);
		
		printf("\n");
		PreOrder(root);
		printf("树的高度为%d\n", TreeHeight(root));
		printf("\n树的叶子节点个数为%d\n", LeafCount(root));
}

void InOrder(BiTree T){
		if(T != NULL) {
				InOrder(T->lchild);
				printf("%d ,",T->data);
				InOrder(T->rchild);
		}
}

void PostOrder(BiTree T){
		if(T != NULL) {
				PostOrder(T->lchild);
				PostOrder(T->rchild);
				printf("%d ,", T->data);
		}
}

void PreOrder(BiTree T){
		if (T != NULL) {
				printf("%d ,", T->data);
				PreOrder(T->lchild);
				PreOrder(T->rchild);
		}
}

int TreeHeight(BiTree T){
		int h = 0;
		if (T != NULL){
				int left = TreeHeight(T->lchild);
				int right = TreeHeight(T->rchild);
				h = left > right ? left + 1 : right + 1;
		}
		return h;
}

int LeafCount(BiTree T){
		if (T == NULL)
				return 0;
		if (T->lchild == NULL && T->rchild == NULL)
				return 1;
		return (LeafCount(T->lchild) + LeafCount(T->rchild));
}
