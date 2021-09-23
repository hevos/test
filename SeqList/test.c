#include "SeqList.h"

void SeqListInit(SL* ps)
{
    ps->a = (SLDataType*)malloc(sizeof(SLDataType)*4);
    if(ps->a == NULL)
    {
        printf("申请空间内存失败\n");
        exit(-1);
    }

    ps->size = 0;
    ps->capacity = 4;
}

void SeqListPrint(SL* ps)
{
    for(int i = 0; i <ps->size; i++)
    {
        printf("%d ", ps->a[i]);
    }
    printf("\n");
}

void SeqListCheckCapaticy(SL* ps)
{
    //如果满了，需要增容
    if(ps->size >= ps->capacity)
    {
        ps->capacity *= 2;
        ps->a = (SLDataType*)realloc(ps->a,
                                     sizeof(SLDataType)*ps->capacity);
        if(ps->a == NULL)
        {
            printf("扩容失败\n");
            exit(-1);
        }
    }
}

void SeqListDestory(SL* ps)
{
    free(ps->a);
    ps->a = NULL;
    ps->size = 0;
    ps->capacity = 0;
}

//尾插尾删  头插头删
void SeqListPushBack(SL* ps, SLDataType x)
{
//    SeqListCheckCapaticy(ps);
//    ps->a[ps->size] = x;
//    ps->size++;

      SeqListInsert(ps, ps->size, x);
}

void SeqListPopBack(SL* ps)
{
//    ps->size--;
      SeqListErase(ps, ps->size-1);
}

void SeqListPushFront(SL* ps, SLDataType x)
{
//    SeqListCheckCapaticy(ps);
//    int end = ps->size - 1;
//    while(end >= 0)
//    {
//        ps->a[end+1] = ps->a[end];
//        end--;
//    }
//    ps->a[0] = x;
//    ps->size++;

      SeqListInsert(ps, 0, x);
}

void SeqListPopFront(SL* ps)
{
//    int start = 0;
//    while(start < ps->size-1)
//    {
//        ps->a[start] = ps->a[start+1];
//        start++;
//    }
//    ps->size--;

      SeqListErase(ps, 0);
}

//任意位置的插入删除
//size_t 就是 unsigned int
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
    //assert(ps);
    //assert(pos <= ps->size && pos >= 0);

    SeqListCheckCapaticy(ps);

    int end = ps->size -1;
    while(end >= pos)
    {
        ps->a[end+1] = ps->a[end];
        end--;
    }

    ps->a[pos] = x;
    ps->size++;
}

void SeqListErase(SL* ps, int pos)
{
    //assert(pos);
    //assert(pos < ps->size && pos >= 0);

    int start = pos;
    while(start < ps->size-1)
    {
        ps->a[start] = ps->a[start+1];
        start++;
    }

    ps->size--;
}

int seqListFind(SL* ps, SLDataType x)
{
    //assert(ps);

    int i = 0;
    while(i < ps->size)
    {
        if(ps->a[i] == x)
        {
            return i;
        }
        ++i;
    }

    return -1;
}
