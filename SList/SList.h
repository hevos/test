#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int SListDataType;

//结点
typedef struct SListNode
{
    SListDataType data;
    struct SListNode* next;
}SListNode;

//struct SList
//{
//    SListNode* head;
//    SListNode* tail;
//    size_t len;
//};

//单链表尾插
void SListPushBack(SListNode** pphead, SListDataType x);
//单链表尾删
void SListPopBack(SListNode** pphead);
//单链表头插
void SListPushFront(SListNode** pphead, SListDataType x);
//单链表头删
void SListPopFront(SListNode** pphead);
//单链表查找
SListNode* SListFind(SListNode* phead, SListDataType x);
//单链表打印
void SListPrint(SListNode* phead);
//动态申请一个结点
SListNode* BuySListNode(SListDataType x);
//单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos , SListDataType x);
//单链表删除pos位置之后的值,分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos);


