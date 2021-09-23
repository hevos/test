#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int SListDataType;

//���
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

//������β��
void SListPushBack(SListNode** pphead, SListDataType x);
//������βɾ
void SListPopBack(SListNode** pphead);
//������ͷ��
void SListPushFront(SListNode** pphead, SListDataType x);
//������ͷɾ
void SListPopFront(SListNode** pphead);
//���������
SListNode* SListFind(SListNode* phead, SListDataType x);
//�������ӡ
void SListPrint(SListNode* phead);
//��̬����һ�����
SListNode* BuySListNode(SListDataType x);
//��������posλ��֮�����x
void SListInsertAfter(SListNode* pos , SListDataType x);
//������ɾ��posλ��֮���ֵ,����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos);


