#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;

typedef struct ListNode
{
    struct ListNode* next;
    struct ListNode* prev;
    LTDataType data;
}ListNode;

//void ListInit(ListNode** pphead);
ListNode* ListInit();
void ListDestory(ListNode** pphead);
void ListClear(ListNode* phead);
ListNode* BuyListNode(LTDataType x);
void ListPrint(ListNode* phead);

void ListPushBack(ListNode* phead, LTDataType x);
void ListPopBack(ListNode* phead);
void ListPushFront(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);

ListNode* ListFind(ListNode* phead, LTDataType x);
//@在pos前面插入x
void ListInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);

