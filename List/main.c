#include "List.h"

//带头双向循环链表

void TestList1()
{
//    ListNode* phead = NULL;
//    ListInit(&phead);

    ListNode* phead = ListInit();
    ListPushBack(phead, 1);
    ListPushBack(phead, 2);
    ListPushBack(phead, 3);
    ListPushBack(phead, 4);
    ListPushBack(phead, 5);

    ListPrint(phead);

    ListPopBack(phead);
    ListPopBack(phead);
    ListPopBack(phead);
    ListPrint(phead);

    ListPushFront(phead, 1);
    ListPushFront(phead, 2);
    ListPushFront(phead, 3);
    ListPushFront(phead, 4);
    ListPrint(phead);

    ListPopFront(phead);
    ListPopFront(phead);
    ListPopFront(phead);
    ListPopFront(phead);
    ListPopFront(phead);
    ListPrint(phead);

    ListDestory(&phead);
}

void TestList2()
{
    ListNode* phead = ListInit();
    ListPushBack(phead, 1);
    ListPushBack(phead, 2);
    ListPushBack(phead, 3);
    ListPushBack(phead, 4);
    ListPrint(phead);

    ListNode* pos = ListFind(phead, 3);
    pos->data = 300;
    ListInsert(pos, 20);
    ListPrint(phead);

    ListErase(pos);
    ListPrint(phead);

    ListDestory(&phead);
}

int main()
{
    TestList1();
    return 0;
}
