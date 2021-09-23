#include "SList.h"

SListNode* BuySListNode(SListDataType x)
{
    SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
    if(newNode == NULL)
    {
        printf("������ʧ��");
        exit(-1);
    }
    newNode->data = x;
    newNode->next = NULL;

    return newNode;
}

//β��
void SListPushBack(SListNode** pphead, SListDataType x)
{
    SListNode* newNode = BuySListNode(x);

    if(*pphead == NULL)
    {
        *pphead = newNode;
    }
    else
    {
        //��β
        SListNode* tail = *pphead;
        while(tail->next != NULL)
        {
            tail = tail->next;
        }

        tail->next = newNode;
    }
}

void SListPopBack(SListNode** pphead)
{
    //1.��
    //2.һ�����
    //2.һ�����Ͻ��
    if(*pphead == NULL)
    {
        return ;
    }
    else if((*pphead)->next == NULL)
    {
        free(*pphead);
        *pphead = NULL;
    }
    else
    {
        SListNode* prev = NULL;
        SListNode* tail = *pphead;
        while(tail->next != NULL)
        {
            prev = tail;
            tail = tail->next;
        }

        free(tail);
        prev->next = NULL;
    }
}

//ͷ��
void SListPushFront(SListNode** pphead, SListDataType x)
{
    SListNode* newNode = BuySListNode(x);
    newNode->next = *pphead;
    *pphead = newNode;
}

//ͷɾ
void SListPopFront(SListNode** pphead)
{
    //1.��
    //2.һ����� + 3.һ�����ϵĽ��
    if(*pphead == NULL)
    {
        return ;
    }
    else
    {
        SListNode* next = (*pphead)->next;
        free(*pphead);

        *pphead = next;
    }
}

//����������
SListNode* SListFind(SListNode* phead, SListDataType x)
{
    SListNode* cur = phead;
    while(cur)
    {
        if(cur->data == x)
        {
            return cur;
        }

        cur = cur->next;
    }

    return NULL;
}

void SListInsertAfter(SListNode* pos , SListDataType x)
{
    //assert(pos);

    SListNode* newnode = BuySListNode(x);
    newnode->next = pos->next;
    pos->next = newnode;
}

void SListEraseAfter(SListNode* pos)
{
    //assert(pos);

    if(pos->next)
    {
        SListNode* next = pos->next;
        SListNode* nextnext = next->next;
        pos->next = nextnext;
        free(next);
    }
}

//������ӡ����
void SListPrint(SListNode* phead)
{
    SListNode* cur = phead;//ָ���һ�����
    while(cur != NULL)
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

