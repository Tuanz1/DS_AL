#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
// 链表结点数据结构
typedef struct Node {
  ElemType data;
  struct Node *next;
} Node, *LinkedList;

LinkedList createList(int list[], int length) {
  Node *head;
  head = (Node *)malloc(sizeof(Node));
  if (head == NULL)
    printf("申请内存失败");
  head->next = NULL;
  // 头插法构造链表
  for (int i = 0; i < length; i++) {
    Node *tmp;
    tmp = (Node *)malloc(sizeof(Node));
    tmp->data = list[i];
    tmp->next = head->next;
    head->next = tmp;
  }
  return head;
}
// 就地逆置
void inverse(LinkedList head) {
  LinkedList r, tmp = head->next;
  head->next = NULL;
  while (tmp != NULL) {
    r = tmp->next;
    tmp->next = head->next;
    head->next = tmp;
    tmp = r;
  }
}
// 合并两个非递减链表，构造成升序链表
LinkedList mergeLink1(LinkedList list1, LinkedList list2) {
  printf("merge");
  LinkedList tmp = list1;
  LinkedList tmp1 = list1->next;
  LinkedList tmp2 = list2->next;
  while (tmp1 != NULL || tmp2 != NULL) {
    printf("Kai");
    if (tmp1->data > tmp2->data) {
      printf("tmp1:%d", tmp1->data);
      tmp->next = tmp1;
      tmp1 = tmp1->next;
    } else {
      printf("tmp2:%d", tmp2->data);
      tmp->next = tmp2;
      tmp2 = tmp2->next;
    }
    tmp = tmp->next;
  }
  return tmp;
}

// 打印链表数据
void printList(LinkedList head) {
  LinkedList tmp = head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
    printf("%d\n", tmp->data);
  }
}
int main() {
  // int list1[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
  int list2[4] = {7, 5, 3, 1};
  int list3[5] = {9, 5, 3, 2, 1};
  // LinkedList l1 = createList(list1, 10);
  LinkedList l2 = createList(list2, 4);
  LinkedList l3 = createList(list3, 5);
  printList(l2);
  printList(l3);
  printf("test");

  // printList(merge);
  return 0;
}
