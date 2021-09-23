#include "List.h"

ListNode* BuyListNode(LTDataType x)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->next = NULL;
    node->prev = NULL;
    node->data = x;

    return node;
}

//void ListInit(ListNode** pphead)
//{
//    *pphead = BuyListNode(0);
//    (*pphead)->next = *pphead;
//    (*pphead)->prev = *pphead;
//}

ListNode* ListInit()
{
    ListNode* phead = BuyListNode(0);
     phead->next = phead;
     phead->prev = phead;

     return phead;
}

void ListPushBack(ListNode* phead, LTDataType x)
{
//    assert(phead);
//
//    ListNode* tail = phead->prev;
//    ListNode* newnode = BuyListNode(x);
//
//    tail->next = newnode;
//    newnode->prev = tail;
//
//    newnode->next = phead;
//    phead->prev = newnode;

    ListInsert(phead, x);
}

void ListPopBack(ListNode* phead)
{
//    assert(phead);
//    assert(phead->next != phead);
//
//    ListNode* tail = phead->prev;
//    ListNode* tailPrev = tail->prev;
//
//    tailPrev->next = phead;
//    phead->prev = tailPrev;
//    free(tail);
//    tail = NULL;

    ListErase(phead->prev);
}

void ListPushFront(ListNode* phead, LTDataType x)
{
//    assert(phead);
//
//    ListNode* first = phead->next;
//    ListNode* newnode = BuyListNode(x);
//
//    phead->next = newnode;
//    newnode->prev = phead;
//
//    newnode->next = first;
//    first->prev = newnode;

    ListInsert(phead->next, x);
}

void ListPopFront(ListNode* phead)
{
//    assert(phead);
//    assert(phead->next != phead);
//
//    ListNode* first = phead->next;
//    ListNode* second = first->next;
//
//    //phead first second
//    phead->next = second;
//    second->prev = phead;
//    free(first);

    ListErase(phead->next);
}

ListNode* ListFind(ListNode* phead, LTDataType x)
{
    assert(phead);
    ListNode* cur = phead->next;
    while(cur != phead)
    {
        if(cur->data == x)
            return cur;

        cur = cur->next;
    }

    return NULL;
}

//在pos前面插入x
void ListInsert(ListNode* pos, LTDataType x)
{
    assert(pos);

    ListNode* posPrev = pos->prev;
    ListNode* newnode = BuyListNode(x);

    //posPrev newnode pos
    posPrev->next = newnode;
    newnode->prev = posPrev;
    newnode->next = pos;
    pos->prev = newnode;
}

void ListErase(ListNode* pos)
{
    assert(pos);

    ListNode* posPrev = pos->prev;
    ListNode* posNext = pos->next;

    free(pos);
    posPrev->next = posNext;
    posNext->prev = posPrev;
}

void ListPrint(ListNode* phead)
{
    assert(phead);
    ListNode* cur = phead->next;
    while(cur != phead)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void ListClear(ListNode* phead)
{
    assert(phead);

    //清理所有的数据结点，保留头节点，可以继续使用
    ListNode* cur = phead;
    while(cur != phead)
    {
        ListNode* next = cur->next;
        free(cur);
        cur = next;
    }

    phead->next = phead;
    phead->prev = phead;
}

void ListDestory(ListNode** pphead)
{
    assert(*pphead);

    //销毁
    ListClear(*pphead);
    free(*pphead);
    *pphead = NULL;
}
