#include<iostream>
using namespace std;

// 单链表
struct Node{
		int data;
		Node *next;
}Node, *LinkList;

int initLink(struct Node *head){
		int data[6] = {1,3,5,7,8,10};
		struct LinkList tmp = *head;
		for(int i = 0; i< 6; i++){
				Node newNode = new Node;
				newNode->data = data[i];
				newNode->next = NULL;
				tmp->next = newNode;
				tmp = tmp->next;
		}
		return 0;
}

void printLink(struct Node head){
		Node tmp = head;
		while(tmp.next != NULL){
				printf("Node:%d", tmp.data);
				tmp = tmp.next;
		}
}
int main(){
		Node head = new Node;
		head.next = NULL;
		initLink(&head);		
		printLink(head);
		return 0;
}
