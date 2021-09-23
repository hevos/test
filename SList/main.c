#include "SList.h"

void TestSList1()
{
    SListNode* pList = NULL;

    SListPushBack(&pList, 1);
    SListPushBack(&pList, 2);
    SListPushBack(&pList, 3);
    SListPushBack(&pList, 4);
    SListPrint(pList);

    SListPopBack(&pList);
    SListPopBack(&pList);
    SListPopBack(&pList);
    SListPopBack(&pList);
    SListPopBack(&pList);
    SListPrint(pList);

    SListPushFront(&pList, 1);
    SListPushFront(&pList, 2);
    SListPushFront(&pList, 3);
    SListPushFront(&pList, 4);
    SListPushFront(&pList, 5);
    SListPrint(pList);

    SListPopBack(&pList);
    SListPopBack(&pList);
    SListPopBack(&pList);
    SListPopBack(&pList);
    SListPopBack(&pList);
    SListPopBack(&pList);
    SListPopBack(&pList);
    SListPrint(pList);
}

void TestSList2()
{
    SListNode* pList = NULL;

    SListPushBack(&pList, 1);
    SListPushBack(&pList, 2);
    SListPushBack(&pList, 3);
    SListPushBack(&pList, 4);
    SListPrint(pList);

    SListNode* pos = SListFind(pList, 3);
    if(pos)
    {
        pos->data = 30;
    }
    SListPrint(pList);

    SListInsertAfter(pos, 23);
    SListPrint(pList);

    SListEraseAfter(pos);
    SListPrint(pList);
}

int main()
{
    TestSList2();
    return 0;
}
