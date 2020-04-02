#define _CRT_SECURE_NO_WARNINGS
#include "myLinkedList.h"
#include <stdio.h>

/**
 *  @name        : Status InitList(LinkList L);
 *	@description : initialize an empty linked list with only the L node without value
 *	@param		 : L(the L node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList L) {

    L->next = NULL;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the L node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList L) {

    LinkedList* temp;
    while (L != NULL) {
        temp = L->next;
        free(L);
        L = temp;
    }
}

/**
 *  @name        : LinkedList InsertList(LinkedList L, LinkedList newNode)
 *	@description : insert a new node after the tail node
 *	@param		 : L(the L node), newNode
 *	@return		 : Status
 *  @notice      : None
 */
LinkedList InsertList(LinkedList L, LinkedList newNode) {

    LinkedList temp = L;
    if (L == NULL) {
        L = newNode;
        newNode->next = NULL;
    }

    else if (newNode != NULL) {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = NULL;
    }

    return L;
}
/**
 *  @name        : LinkedList DeleteList(LinkedList L, ElemType e)
 *	@description : delete the first node after the head node L and assign its value to e
 *	@param		 : L, e
 *	@return		 : Status
 *  @notice      : None
 */
LinkedList DeleteList(LinkedList L, ElemType e) {
    
    LinkedList temp01 = L;   
    LinkedList temp02 = L;   
    while (temp02 != NULL) {
        if (strcmp(temp02->num, e) == 0) {
            if (temp02 == L) { 
                L = L->next;  
            }
            else {
                temp01->next = temp02->next; 
            }
            free(temp02);  // 匹配成功则将其删除
            break;
        }
        
        temp01 = temp02;  
        temp02 = temp02->next;  
    }
   
    return L;  
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the L node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L) {
    while (L != NULL) {
        printf("%d\n", L->num);
        L = L->next;
    }
}
/*
void TraverseList(LinkedList L, void (*visit)(LinkedList)) {

    visit = link_print(L);
    printf(visit);
}
*/

/**
 *  @name        : LinkedList SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the L node), e
 *	@return		 : Status
 *  @notice      : None
 */
LinkedList SearchList(LinkedList L, ElemType e) {

    while (L != NULL) {
        if (strcmp(L->num, e) == 0)
            break;
        L = L->next;
    }
    if (L != NULL) {
        printf("%s", L->num);
    }
    
    return L;
}

/**
 *  @name        : LinkedList ReverseList(LinkedList L)
 *	@description : reverse the linked list
 *	@param		 : L(the L node)
 *	@return		 : Status
 *  @notice      : None
 */
LinkedList ReverseList(LinkedList L) {
    
    LinkedList temp01 = L; 
    LinkedList temp02; 
    LinkedList temp03;  

    if (L == NULL) 
        return ERROR;
    temp02 = temp01->next;  
    while (temp02 != NULL)
    {
        temp03 = temp02->next;  
        temp02->next = temp01;  
        temp01 = temp02;  
        temp02 = temp03; 
    }
    L->next = NULL;  
    L = temp01;  

    return L;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the L node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    
    LinkedList fast = L, slow = L;
    while (fast->next && slow->next) {
        fast = fast->next;
        if (NULL == (slow = slow->next->next))
            return ERROR; // 无环
        if (fast == slow)
            return SUCCESS;
    }
}

/**
 *  @name        : LinkedList* ReverseEvenList(LinkedList L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the L node)
 *	@return		 : LinkedList(the new L node)
 *  @notice      : choose to finish
 */
LinkedList* ReverseEvenList(LinkedList* L) {

}

/**
 *  @name        : LinkedList* FindMidNode(LinkedList L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the L node)
 *	@return		 : LinkedList
 *  @notice      : choose to finish
 */
LinkedList* FindMidNode(LinkedList* L) {

}

void print_help(void) {
    printf("************************************************\n");
    printf("         欢迎来到简易版单向链表管理系统\n");
    printf("************************************************\n");
    printf("        输入 1 插入新节点\n");
    printf("        输入 2 遍历链表\n");
    printf("        输入 3 查找节点信息\n");
    printf("        输入 4 删除节点信息\n");
    printf("        输入 5 逆序排列\n");
    printf("        输入 6 检测是否为循环链表\n");
    printf("        输入 7 查看帮助信息\n");
    printf("       输入 8 销毁所有信息并退出管理系统\n");
    printf("************************************************\n");
}

int main(void) {

    LinkedList newNode, L = NULL;
    ElemType ops, num02;

    print_help();
    while (1)
    {
        printf("Please input the ops：");
        scanf("%d", &ops);

        switch (ops)
        {
        case 1: // insert a node
            newNode = (LinkedList)malloc(sizeof(LNode));
            puts("Please input the node's information：");
            scanf("%d", &(newNode->num));
            L = InsertList(L, newNode);
            break;
        case 2:
            if (L == NULL)
                puts("No Information");
            else
                puts("The information is as follows：");
            TraverseList(L);
            break;
        case 3:
            printf("Please input the node to search：\n");
            scanf("%d", &num02);
            LinkedList p = SearchList(L, num02);
            if (p != NULL)
                printf("%d\n", p->num);
            else
                printf("No Relevant Information.");
            break;
        case 4:
            puts("Please input the node to delete：");
            scanf("%d", num02);
            L = DeleteList(L , num02);
            puts("SUCCESSFUL");
            TraverseList(L);
            break;
        case 5:
            L = ReverseList(L);
            break;
        case 6:
            IsLoopList(L);
            break;
        case 7:
            print_help();
            break;
        case 8:
            puts("退出成功");
            DestroyList(L);
            return 0;
            break;
        }
    }
}