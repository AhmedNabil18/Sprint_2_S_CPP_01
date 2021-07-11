#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#define NULL_PTR (void *)0
#define MAX_STACK 100

/****************************************************************
 ********************* Linked List Partition ********************
 ****************************************************************/

typedef struct
{

}str_LinkedList_Data_t;

typedef struct LinkedList_Node
{
    str_LinkedList_Data_t stData;
    struct LinkedList_Node* next;
}str_LinkedList_Node;

typedef struct
{
    str_LinkedList_Node* Head;
    uint32_t Size;
}str_LinkedList;

uint32_t LinkedList_getSize(str_LinkedList * L_list);
str_LinkedList * LinkedList_Create(void);
void LinkedList_Clear(str_LinkedList *L_list);
void LinkedList_PushHead(str_LinkedList* L_list, str_LinkedList_Data_t stData);
str_LinkedList_Data_t LinkedList_PopHead(str_LinkedList* L_list);
void LinkedList_PushTail(str_LinkedList* L_list, str_LinkedList_Data_t stData);
str_LinkedList_Data_t LinkedList_PopTail(str_LinkedList* L_list);
void LinkedList_InsertNode(str_LinkedList * L_list, uint32_t position, str_LinkedList_Data_t stData);
str_LinkedList_Node * LinkedList_valueFind(str_LinkedList * L_list, str_LinkedList_Data_t stData);
str_LinkedList_Node * LinkedList_positionFind(str_LinkedList * L_list, uint32_t position);

void LinkedList_InsertNode_SortedASC(str_LinkedList* L_list, str_LinkedList_Data_t stData);
str_LinkedList* LinkedList_MergeLists_SortedASC(str_LinkedList* list1, str_LinkedList* list2);





#endif
