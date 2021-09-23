#include "SeqList.h"

//≤‚ ‘Õ∑Œ≤≤Â»Î…æ≥˝
void TestSeqList()
{
    SeqList s;
    SeqListInit(&s);
    SeqListPushBack(&s, 1);
    SeqListPushBack(&s, 2);
    SeqListPushBack(&s, 3);
    SeqListPushBack(&s, 4);
    SeqListPushBack(&s, 5);
    SeqListPushBack(&s, 6);
    SeqListPushBack(&s, 7);
    SeqListPushBack(&s, 8);
    SeqListPushBack(&s, 9);
    SeqListPrint(&s);

    SeqListPopBack(&s);
    SeqListPopBack(&s);
    SeqListPrint(&s);

    SeqListPushFront(&s, -1);
    SeqListPushFront(&s, -2);
    SeqListPushFront(&s, -3);
    SeqListPushFront(&s, -4);
    SeqListPrint(&s);

    SeqListPopFront(&s);
    SeqListPopFront(&s);
    SeqListPrint(&s);

    int pos = seqListFind(&s,5);
    if(pos != -1)
    {
        SeqListErase(&s, pos);
    }
    SeqListPrint(&s);

    SeqListDestory(&s);
}

int main()
{
    TestSeqList();
    return 0;
}
