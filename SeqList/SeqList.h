#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int SLDataType;
#define N 10

//顺序表，有效数组在数据中必须是连续的
//静态数据表设计（固定大小）
//struct SeqList
//{
//    SLDataType a[N];
//    int size;
//};

typedef struct SeqList
{
    SLDataType* a;
    int size;//有效个数大小
    int capacity;//容量
}SL,SeqList;

//初始化
void SeqListInit(SL* ps);
//输出
void SeqListPrint(SL* ps);
//检查扩容
void SeqListCheckCapaticy(SL* ps);
//销毁
void SeqListDestory(SL* ps);

//尾插尾删  头插头删
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);

//任意位置的插入删除
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);

//顺序表查找
int seqListFind(SL* ps, SLDataType x);
