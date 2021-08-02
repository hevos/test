#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED
#include <stdio.h>
#include <string.h>

#define MAX 1000

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

enum Option
{
    EXIT,//0
    ADD,//1
    DEL,//2
    SEARCH,//3
    MODIFY,//4
    SHOW,//5
    SORT//6
};

struct PeoInfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
};

//ͨѶ¼����
struct Contact
{
    struct PeoInfo data[MAX];//���һ����Ϣ
    int size;//��¼��ǰ�Ѿ��е�Ԫ�ظ���
};

//��������

//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps);

//����һ����Ϣ��ͨѶ¼
void AddContact(struct Contact* ps);

//��ӡͨѶ¼��Ϣ
void ShowContact(const struct Contact* ps);

//ɾ��ָ������ϵ��
void DelContact(struct Contact* ps);

//����ָ�����˵���Ϣ
void SearchContact(const struct Contact* ps);

//�޸�ָ����ϵ��
void ModifyContact(struct Contact* ps);

//����ͨѶ¼������
void SortContact(struct Contact* ps);

#endif // CONTACT_H_INCLUDED

/*
ͨѶ¼��Ҫʵ�ֵĹ��ܣ�
1.���1000�����ѵ���Ϣ
    ����
    �绰
    �Ա�
    ��ַ
    ����

2.���Ӻ�����Ϣ
3.ɾ��ָ�����ֵĺ�����Ϣ
4.���Һ�����Ϣ
5.�޸ĺ�����Ϣ
6.��ӡ������Ϣ
7.����
*/

