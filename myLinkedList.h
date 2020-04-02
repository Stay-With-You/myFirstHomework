/* --------------------------------Revision History--------------------------------------
* No	version		Data			Revised By			Item			Description
*
*
*************************************************************************************** /

/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct LinkedList {
    ElemType num;
    struct LinkedList* next;
} LNode, * LinkedList;

// define Status
typedef enum Status {
    ERROR,
    SUCCESS
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : Status InitList(LinkList L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList L);

/**
 *  @name        : void DestroyList(LinkedList L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList L);

/**
 *  @name        : LinkedList InsertList(LinkedList L, LinkedList newNode)
 *	@description : insert a new node after the whole link 
 *	@param		 : L, newNode
 *	@return		 : Status
 *  @notice      : None
 */
LinkedList InsertList(LinkedList L, LinkedList newNode);

/**
 *  @name        : Status DeleteList(LinkedList L, ElemType e)
 *	@description : delete the first node after the head node L and assign its value to e
 *	@param		 : L, e
 *	@return		 : Status
 *  @notice      : None
 */
LinkedList DeleteList(LinkedList p, ElemType e);

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e));

/**
 *  @name        : void TraverseList(LinkedList L)
 *	@description : traverse the linked list 
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L);

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
LinkedList SearchList(LinkedList L, ElemType e);

/**
 *  @name        : Status ReverseList(LinkedList L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
LinkedList ReverseList(LinkedList L);

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L);

/**
 *  @name        : LinkedList* ReverseEvenList(LinkedList L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LinkedList(the new head node)
 *  @notice      : choose to finish
 */
LinkedList* ReverseEvenList(LinkedList L);

/**
 *  @name        : LinkedList* FindMidNode(LinkedList L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LinkedList
 *  @notice      : choose to finish
 */
LinkedList* FindMidNode(LinkedList L);

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
