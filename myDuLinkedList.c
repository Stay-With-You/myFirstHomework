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
	if (strcmp(temp->num, num02) == 0) {  // �ҵ��˾�ɾ����
		if (temp != head) { // ɾ���Ĳ���ͷ�ڵ�
			temp->prior->next = temp->next;  // ��ָ��ָ��
			temp->next->prior = temp->prior;
		}
		else {  // ɾ������ͷ�ڵ�	
			if (head->next == head)  // ����Ƿ�ֹֻ��һ����ͷ���ڵ�����
				head = NULL;
			else { // �������ϵĽڵ�
				head = head->next;  // ɾ������ͷ�ڵ㣬����ɾ���ͷ�ڵ�Ӧ�ú���
				temp->prior->next = temp->next;
				temp->next->prior = temp->prior;
			}
			free(temp);  // �ͷ�ƥ�䵽�Ľڵ�
		}
	}
		return head;
}

DuLinkedList InsertBeforeList_DuL(DuLNode* head, DuLNode* newNode) {
	
	DuLinkedList temp = head;
	if (head == NULL) {
		head = newNode;
		head->next = head;  // ��һ��ָ��ָ���Լ�
		head->prior = head;  // ǰһ��ָ��Ҳָ���Լ�
		// һ���ڵ������㶨
	}

	else if (newNode != NULL)  // �ж�Ҫ����Ľڵ��Ƿ���ڵ�
	{
		temp = head->prior;  // ���������߼��ϣ����һ���ڵ���ͷ�ڵ�֮ǰ�ˣ�

		newNode->next = temp->next; // �Ȱ�Ҫ����Ľڵ��ָ��ָ�����Ľڵ�
		temp->next = newNode; // �ٰ�ԭ��ǰ��Ľڵ��ָ��ĳ�ָ��Ҫ����Ľڵ�
		newNode->prior = temp;  // �ı�ǰָ��
		newNode->next->prior = newNode;
	}
	return head;
}

DuLinkedList InsertAfterList_DuL(DuLNode* head, DuLNode* newNode) {

	DuLinkedList temp = head;
	if (head == NULL) {
		head = newNode;
		head->next = head;  // ��һ��ָ��ָ���Լ�
		head->prior = head;  // ǰһ��ָ��Ҳָ���Լ�
		// һ���ڵ������㶨
	}

	else if (newNode != NULL)  // �ж�Ҫ����Ľڵ��Ƿ���ڵ�
	{
		newNode->next = temp->next; // �Ȱ�Ҫ����Ľڵ��ָ��ָ�����Ľڵ�
		temp->next = newNode; // �ٰ�ԭ��ǰ��Ľڵ��ָ��ĳ�ָ��Ҫ����Ľڵ�
		newNode->prior = temp;  // �ı�ǰָ��
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
	if (strcmp(temp->num, num02) == 0) {  // �ҵ��˾�ɾ����
		if (temp != head) { // ɾ���Ĳ���ͷ�ڵ�
			temp->prior->next = temp->next;  // ��ָ��ָ��
			temp->next->prior = temp->prior;
		}
		else {  // ɾ������ͷ�ڵ�	
			if (head->next == head)  // ����Ƿ�ֹֻ��һ����ͷ���ڵ�����
				head = NULL;
			else { // �������ϵĽڵ�
				head = head->next;  // ɾ������ͷ�ڵ㣬����ɾ���ͷ�ڵ�Ӧ�ú���
				temp->prior->next = temp->next;
				temp->next->prior = temp->prior;
			}
			free(temp);  // �ͷ�ƥ�䵽�Ľڵ�
		}
	}

	return head;
}


void TraverseList(DuLinkedList head) {

	DuLinkedList temp = head;
	if (head == NULL)
		return;   // ���ж�ͷ�ڵ��Ƿ�Ϊ��
	while (temp->next != head) {  // ����жϵ����һ���ڵ�������˳��ˣ������ǲ��������һ���ڵ��
		printf("%d\n", temp->num);
		temp = temp->next;
	}
	printf("%d\n", temp->num);   // �������һ���ڵ�����
}

void print_help(void) {
	printf("************************************************\n");
	printf("         ��ӭ�������װ�˫��ѭ���������ϵͳ\n");
	printf("************************************************\n");
	printf("        ���� 1 ��ǰ����ڵ�\n");
	printf("        ���� 2 �������ڵ�\n");
	printf("        ���� 3 ����������Ϣ\n");
	printf("        ���� 4 ɾ���ڵ���Ϣ\n");
	printf("        ���� 5 �鿴������Ϣ\n");
	printf("       ���� 6 ����������Ϣ���˳�����ϵͳ\n");
	printf("************************************************\n");
}

int main(void) {

	DuLinkedList newNode, L = NULL;
	ElemType ops, num02;

	print_help();
	while (1)
	{
		printf("Please input the ops��");
		scanf("%d", &ops);

		switch (ops)
		{
		case 1:  // insert a node in front of the link
			newNode = (DuLinkedList)malloc(sizeof(DuLNode));
			puts("Please input the node's information��");
			scanf("%d", &(newNode->num));
			L = InsertBeforeList_DuL(L, newNode);
			break;
		case 2:  // insert a node at the end of the link
			newNode = (DuLinkedList)malloc(sizeof(DuLNode));
			puts("Please input the node's information��");
			scanf("%d", &(newNode->num));
			L = InsertAfterList_DuL(L, newNode);
			break;
		case 3:  // Traverse
			if (L == NULL)
				puts("No Information");
			else
				puts("The information is as follows��");
			TraverseList(L);
			break;
		case 4:  // delete the node
			puts("Please input the node to delete��");
			scanf("%d", num02);
			L = DeleteList_DuL(L, num02);
			puts("SUCCESSFUL");
			TraverseList(L);
			break;
		case 5:
			print_help();
			break;
		case 6:  // destory the information
			puts("�˳��ɹ�");
			DestroyList_DuL(L);
			return 0;
			break;
		}
	}

}