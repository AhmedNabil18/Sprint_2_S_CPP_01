#include <stdlib.h>
#include <stdio.h>
#include "Platform_Types.h"
#include "LinkedList.h"



/****************************************************************
 ********************* Linked List Partition ********************
 ****************************************************************/


/*************************************************************************************
* Service Name: LinkedList_Create
* Parameters (in): None
* Parameters (inout): None
* Parameters (out):None
* Return value: str_LinkedList * -> Pointer to the created Linked List.
* Description: Function to create a new linked list and return the pointer to this list.
* *************************************************************************************/
str_LinkedList * LinkedList_Create(void)
{
    str_LinkedList * L_list = (str_LinkedList *) malloc(sizeof(str_LinkedList));
    L_list->Head = NULL_PTR;
    L_list->Size = 0;
    return L_list;
}

/************************************************************************************
* Service Name: LinkedList_Clear
* Parameters (in): L_list -> Pointer to a Linked List
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to clear an already created linked list.
************************************************************************************/
void LinkedList_Clear(str_LinkedList *L_list)
{
    free(L_list);
}

/************************************************************************************
* Service Name: LinkedList_getSize
* Parameters (in): L_list -> Pointer to a Linked List
* Parameters (inout): None
* Parameters (out):None
* Return value: int -> Size of the Linked List (Number of Node inside the Linked List)
* Description: Function to return the size of the linked list.
************************************************************************************/
uint32_t LinkedList_getSize(str_LinkedList * L_list)
{
    int i=1;
    str_LinkedList_Node * node = L_list->Head;
    if(L_list->Head == NULL_PTR) return 0;
    while(node->next != NULL_PTR)
    {
        node = node->next;
        i++;
    }
    return i;
}

/************************************************************************************
* Service Name: LinkedList_PushHead
* Parameters (in): L_list -> Pointer to a Linked List
                   newData -> the value of the data will be saved in the new node
* Parameters (inout): None
* Parameters (out):None
* Return value: None
* Description: Function to insert a new node with a new data value at the head of the linked list.
************************************************************************************/
void LinkedList_PushHead(str_LinkedList* L_list, str_LinkedList_Data_t stData)
{
    str_LinkedList_Node* node = (str_LinkedList_Node*)malloc(sizeof(str_LinkedList_Node));

    node->data = newData;
    node->next = L_list->Head;
    L_list->Head = node;
    L_list->Size++;
}

/************************************************************************************
* Service Name: LinkedList_PopHead
* Parameters (in): L_list -> Pointer to a Linked List.
* Parameters (inout): None
* Parameters (out):None
* Return value: int -> The value of the data inside the Head node.
* Description: Function to pop the head node in the linked list and return its data.
************************************************************************************/
int LinkedList_PopHead(str_LinkedList* L_list)
{
    if(L_list->Head == NULL_PTR)
    {
        printf("Error, There are no nodes in this list to pop");
        return 0;
    }
    str_LinkedList_Node *node = L_list->Head;
    int data = node->data;

    L_list->Head = node->next;
    L_list->Size--;
    free(node);

    return data;

}

/************************************************************************************
* Service Name: LinkedList_PushTail
* Parameters (in): L_list -> Pointer to a Linked List
                   newData -> the value of the data will be saved in the new node
* Parameters (inout): None
* Parameters (out):None
* Return value: None
* Description: Function to insert a new node with a new data value at the tail of the linked list.
************************************************************************************/
void LinkedList_PushTail(str_LinkedList* L_list, int newData)
{
    str_LinkedList_Node* node = (str_LinkedList_Node*)malloc(sizeof(str_LinkedList_Node));

    node->data = newData;
    node->next = NULL_PTR;

    if(L_list->Head == NULL_PTR) L_list->Head = node;
    else
    {
        str_LinkedList_Node* temp_node= L_list->Head;

        while(temp_node->next != NULL_PTR)
            temp_node = temp_node->next;

        temp_node->next = node;
    }
    L_list->Size++;
}

/************************************************************************************
* Service Name: LinkedList_PopTail
* Parameters (in): L_list -> Pointer to a Linked List.
* Parameters (inout): None
* Parameters (out):None
* Return value: int -> The value of the data inside the Tail node.
* Description: Function to pop the tail node in the linked list and return its data.
************************************************************************************/
int LinkedList_PopTail(str_LinkedList* L_list)
{
    if(L_list->Head == NULL_PTR)
    {
        printf("Error, There are no nodes in this list to pop");
        return 0;
    }
    str_LinkedList_Node * node = L_list->Head;
    str_LinkedList_Node * node2 = NULL_PTR;
    while(node->next != NULL_PTR)
    {
        node2 = node;
        node = node->next;
    }

    int data = node->data;

    if(node2 == NULL_PTR)
        L_list->Head = NULL_PTR;
    else
        node2->next = NULL_PTR;
    free(node);
    L_list->Size--;
    return data;
}

/************************************************************************************
* Service Name: LinkedList_InsertNode
* Parameters (in): L_list -> Pointer to a Linked List.
                   position -> The index or the position of the node to be inserted.
                   newData -> the value of the data will be saved in the new node.
* Parameters (inout): None
* Parameters (out):None
* Return value: None.
* Description: Function to insert a new node in a specific position inside the linked list.
************************************************************************************/
void LinkedList_InsertNode(str_LinkedList * L_list, uint32_t position, str_LinkedList_Data_t stData)
{
    if(position > (L_list->Size+1))
    {
        printf("Error, no such position %d in this list \n", position);
        return;
    }else if((position == (L_list->Size+1)) || (L_list->Size == 0))
    {
        LinkedList_PushTail(L_list, newData);
        return;
    }else if(position == 1)
    {
        LinkedList_PushHead(L_list, newData);
        return;
    }
    str_LinkedList_Node *left=L_list->Head, *right=NULL_PTR;

    while(position != 2 && --position) left = left->next;
    right = left->next;

    str_LinkedList_Node * node = (str_LinkedList_Node *)malloc(sizeof(str_LinkedList_Node));
    node->data = newData;
    node->next = right;
    left->next = node;
    L_list->Size++;
}

/************************************************************************************
* Service Name: LinkedList_valueFind
* Parameters (in): L_list -> Pointer to a Linked List.
                   value -> The value that will be searched for.
* Parameters (inout): None
* Parameters (out):None
* Return value: str_LinkedList_Node -> Pointer to the node that holds the value.
* Description: Function used to search for a given value if it's in the linked list or not.
************************************************************************************/
str_LinkedList_Node * LinkedList_valueFind(str_LinkedList * L_list, str_LinkedList_Data_t stData)
{
    if(L_list->Size == 0) return NULL_PTR;
    str_LinkedList_Node * node = L_list->Head;

    while(node->data != value)
    {
        if(node->next == NULL_PTR) return NULL_PTR;
        node = node->next;
    }
    return node;
}

/************************************************************************************
* Service Name: LinkedList_positionFind
* Parameters (in): L_list -> Pointer to a Linked List.
                   position -> The position of the node that will be searched for.
* Parameters (inout): None
* Parameters (out):None
* Return value: str_LinkedList_Node -> Pointer to the node that located in this position.
* Description: Function used to search for a node in a given position.
************************************************************************************/
str_LinkedList_Node * LinkedList_positionFind(str_LinkedList * L_list, uint32_t position)
{
    if(L_list->Size == 0 || position > L_list->Size) return NULL_PTR;
    str_LinkedList_Node * node = L_list->Head;

    while(--position)
        node = node->next;

    return node;
}

/************************************************************************************
* Service Name: LinkedList_InsertNode_SortedASC
* Parameters (in): L_list -> Pointer to a Linked List.
                   newData -> the value of the data will be saved in the new node.
* Parameters (inout): None
* Parameters (out):None
* Return value: None
* Description: Function used to insert a new node in an ascending sorted linked list.
************************************************************************************/
void LinkedList_InsertNode_SortedASC(str_LinkedList* L_list, str_LinkedList_Data_t stData)
{
    if(L_list->Size == 0)
    {
        LinkedList_PushTail(L_list, newData);
        return;
    }

    str_LinkedList_Node *node = L_list->Head;
    if(newData<node->data)
    {
        LinkedList_PushHead(L_list, newData);
        return;
    }

    int index = 2;
    node = node->next;

    while(newData > node->data)
    {
        index++;
        node = node->next;
        if(node == NULL_PTR) break;
    }
    LinkedList_InsertNode(L_list, index, newData);
}


/************************************************************************************
* Service Name: LinkedList_MergeLists_SortedASC
* Parameters (in): list1 -> Pointer to the first sorted linked list.
                   list2 -> Pointer to the second sorted linked list.
* Parameters (inout): None
* Parameters (out):None
* Return value: str_LinkedList* -> A pointer to the new sorted linked list.
* Description: Function used to merge two sorted linked lists to a new sorted list.
************************************************************************************/
str_LinkedList* LinkedList_MergeLists_SortedASC(str_LinkedList* list1, str_LinkedList* list2)
{
    if((list1 == NULL_PTR) || (list1->Size == 0)) return list2;
    else if((list2 == NULL_PTR)  || (list2->Size == 0)) return list1;
    else if(((list1 == NULL_PTR) && (list2 == NULL_PTR))
            || ((list1->Size == 0) && (list2->Size == 0)))
                return NULL_PTR;

    str_LinkedList *merged = LinkedList_Create();
    int merged_index=1;
    int merged_size= list1->Size + list2->Size;

    str_LinkedList_Node* node1 = list1->Head;
    str_LinkedList_Node* node2 = list2->Head;

    while(--merged_size)
    {

        if((node1->data) < (node2->data))
        {
            LinkedList_InsertNode(merged, merged_index++, node1->data);
            node1=node1->next;
        }else
        {
            LinkedList_InsertNode(merged, merged_index++, node2->data);
            node2=node2->next;
        }
    }
}
