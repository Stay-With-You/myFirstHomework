#define _CRT_SECURE_NO_WARNINGS
#include "myDuLinkedList.h"
#include <stdio.h>

Status InitList_DuL(DuLinkedList head) {
	
	DuLinkedList temp = head;
	if (head == NULL) {
		head->next = head;
		head->prior = head;
	}
	return SUCCESS;
}

void DestroyList_DuL(DuLinkedList head, ElemType num02) {
	DuLinkedList temp = head;
	if (head == NULL)
		printf("No Information");
	return;
	while (temp->next != head) {
		if (strcmp(temp->num, num02) == 0)
			break;
		temp = temp->next;
	}
	if (strcmp(temp->num, num02) == 0) {  // 找到了就删除掉
		if (temp != head) { // 删除的不是头节点
			temp->prior->next = temp->next;  // 改指针指向
			temp->next->prior = temp->prior;
		}
		else {  // 删除的是头节点	
			if (head->next == head)  // 这个是防止只有一个（头）节点的情况
				head = NULL;
			else { // 两个以上的节点
				head = head->next;  // 删除的是头节点，所以删完后头节点应该后移
				temp->prior->next = temp->next;
				temp->next->prior = temp->prior;
			}
			free(temp);  // 释放匹配到的节点
		}
	}
		return head;
}

DuLinkedList InsertBeforeList_DuL(DuLNode* head, DuLNode* newNode) {
	
	DuLinkedList temp = head;
	if (head == NULL) {
		head = newNode;
		head->next = head;  // 后一个指针指向自己
		head->prior = head;  // 前一个指针也指向自己
		// 一个节点的情况搞定
	}

	else if (newNode != NULL)  // 判断要插入的节点是否存在的
	{
		temp = head->prior;  // 即现在在逻辑上，最后一个节点在头节点之前了！

		newNode->next = temp->next; // 先把要插入的节点的指向指向后面的节点
		temp->next = newNode; // 再把原来前面的节点的指向改成指向要插入的节点
		newNode->prior = temp;  // 改变前指针
		newNode->next->prior = newNode;
	}
	return head;
}

DuLinkedList InsertAfterList_DuL(DuLNode* head, DuLNode* newNode) {

	DuLinkedList temp = head;
	if (head == NULL) {
		head = newNode;
		head->next = head;  // 后一个指针指向自己
		head->prior = head;  // 前一个指针也指向自己
		// 一个节点的情况搞定
	}

	else if (newNode != NULL)  // 判断要插入的节点是否存在的
	{
		newNode->next = temp->next; // 先把要插入的节点的指向指向后面的节点
		temp->next = newNode; // 再把原来前面的节点的指向改成指向要插入的节点
		newNode->prior = temp;  // 改变前指针
		newNode->next->prior = newNode;
	}
	return head;
}

DuLinkedList DeleteList_DuL(DuLNode* head, ElemType num02) {
	
	DuLinkedList temp = head;
	if (head == NULL)
	printf("No Information");
	return;
	while (temp->next != head) {
		if (strcmp(temp->num, num02) == 0)
			break;
		temp = temp->next;
	}
	if (strcmp(temp->num, num02) == 0) {  // 找到了就删除掉
		if (temp != head) { // 删除的不是头节点
			temp->prior->next = temp->next;  // 改指针指向
			temp->next->prior = temp->prior;
		}
		else {  // 删除的是头节点	
			if (head->next == head)  // 这个是防止只有一个（头）节点的情况
				head = NULL;
			else { // 两个以上的节点
				head = head->next;  // 删除的是头节点，所以删完后头节点应该后移
				temp->prior->next = temp->next;
				temp->next->prior = temp->prior;
			}
			free(temp);  // 释放匹配到的节点
		}
	}

	return head;
}


void TraverseList(DuLinkedList head) {

	DuLinkedList temp = head;
	if (head == NULL)
		return;   // 先判断头节点是否为空
	while (temp->next != head) {  // 这个判断到最后一个节点就马上退出了，所以是不包括最后一个节点的
		printf("%d\n", temp->num);
		temp = temp->next;
	}
	printf("%d\n", temp->num);   // 补上最后一个节点的输出
}

void print_help(void) {
	printf("************************************************\n");
	printf("         欢迎来到简易版双向循环链表管理系统\n");
	printf("************************************************\n");
	printf("        输入 1 往前插入节点\n");
	printf("        输入 2 往后插入节点\n");
	printf("        输入 3 遍历链表信息\n");
	printf("        输入 4 删除节点信息\n");
	printf("        输入 5 查看帮助信息\n");
	printf("       输入 6 销毁所有信息并退出管理系统\n");
	printf("************************************************\n");
}

int main(void) {

	DuLinkedList newNode, L = NULL;
	ElemType ops, num02;

	print_help();
	while (1)
	{
		printf("Please input the ops：");
		scanf("%d", &ops);

		switch (ops)
		{
		case 1:  // insert a node in front of the link
			newNode = (DuLinkedList)malloc(sizeof(DuLNode));
			puts("Please input the node's information：");
			scanf("%d", &(newNode->num));
			L = InsertBeforeList_DuL(L, newNode);
			break;
		case 2:  // insert a node at the end of the link
			newNode = (DuLinkedList)malloc(sizeof(DuLNode));
			puts("Please input the node's information：");
			scanf("%d", &(newNode->num));
			L = InsertAfterList_DuL(L, newNode);
			break;
		case 3:  // Traverse
			if (L == NULL)
				puts("No Information");
			else
				puts("The information is as follows：");
			TraverseList(L);
			break;
		case 4:  // delete the node
			puts("Please input the node to delete：");
			scanf("%d", num02);
			L = DeleteList_DuL(L, num02);
			puts("SUCCESSFUL");
			TraverseList(L);
			break;
		case 5:
			print_help();
			break;
		case 6:  // destory the information
			puts("退出成功");
			DestroyList_DuL(L);
			return 0;
			break;
		}
	}

}