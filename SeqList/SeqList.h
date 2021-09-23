#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int SLDataType;
#define N 10

//˳�����Ч�����������б�����������
//��̬���ݱ���ƣ��̶���С��
//struct SeqList
//{
//    SLDataType a[N];
//    int size;
//};

typedef struct SeqList
{
    SLDataType* a;
    int size;//��Ч������С
    int capacity;//����
}SL,SeqList;

//��ʼ��
void SeqListInit(SL* ps);
//���
void SeqListPrint(SL* ps);
//�������
void SeqListCheckCapaticy(SL* ps);
//����
void SeqListDestory(SL* ps);

//β��βɾ  ͷ��ͷɾ
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);

//����λ�õĲ���ɾ��
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);

//˳������
int seqListFind(SL* ps, SLDataType x);
