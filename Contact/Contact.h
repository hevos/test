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

//通讯录类型
struct Contact
{
    struct PeoInfo data[MAX];//存放一个信息
    int size;//记录当前已经有的元素个数
};

//声明函数

//初始化通讯录
void InitContact(struct Contact* ps);

//增加一个信息到通讯录
void AddContact(struct Contact* ps);

//打印通讯录信息
void ShowContact(const struct Contact* ps);

//删除指定的联系人
void DelContact(struct Contact* ps);

//查找指定的人的信息
void SearchContact(const struct Contact* ps);

//修改指定联系人
void ModifyContact(struct Contact* ps);

//排序通讯录的内容
void SortContact(struct Contact* ps);

#endif // CONTACT_H_INCLUDED

/*
通讯录所要实现的功能：
1.存放1000个好友的信息
    名字
    电话
    性别
    地址
    年龄

2.增加好友信息
3.删除指定名字的好友信息
4.查找好友信息
5.修改好友信息
6.打印好友信息
7.排序
*/

