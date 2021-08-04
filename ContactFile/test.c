#include "ContactFile.h"

//声明函数
void CheckCapacity(struct Contact* ps);

//加载文件中的信息到通讯录中
void LoadContact(Contact* ps)
{
    PeoInfo tmp = {0};
    FILE* pfRead = fopen("contact.txt", "rb");
    if(pfRead == NULL)
    {
        printf("LoadContact::%s\n", strerror(errno));
        return ;
    }
    //读取文件，存放到通讯录中
    while(fread(&tmp, sizeof(PeoInfo), 1, pfRead))
    {
        CheckCapacity(ps);
        ps->data[ps->size] = tmp;
        ps->size++;
    }
    //关闭文件
    fclose(pfRead);
    pfRead = NULL;
}

//初始化通讯录
void InitContact(struct Contact* ps)
{
    ps->data = (struct PeoInfo*)malloc(DEFAULT_SZ*sizeof(struct PeoInfo));
    if(ps->data == NULL)
    {
        return;
    }
    ps->size = 0;
    ps->capacity = DEFAULT_SZ;
    //把文件中已经存放的通讯录中的信息加载到通讯录中
    LoadContact(ps);
}

void CheckCapacity(struct Contact* ps)
{
    if(ps->size == ps->capacity)
    {
        //增容
        struct PeoInfo* ptr = realloc(ps->data,(ps->capacity+2)*sizeof(PeoInfo));
        if(ptr != NULL)
        {
            ps->data = ptr;
            ps->capacity += 2;
            printf("增容成功\n");
        }
        else
        {
            printf("增容失败\n");
        }
    }
}

//增加一个信息到通讯录
void AddContact(struct Contact* ps)
{
    //检测当前通讯录的容量
    //1.如果满了，就增加空间
    //2.如果不满，啥事都不干
    CheckCapacity(ps);
    //增加数据
    printf("请输入名字：>");
    scanf("%s", ps->data[ps->size].name);
    printf("请输入年龄：>");
    scanf("%d", &(ps->data[ps->size].age));
    printf("请输入性别：>");
    scanf("%s", ps->data[ps->size].sex);
    printf("请输入电话：>");
    scanf("%s", ps->data[ps->size].tele);
    printf("请输入地址：>");
    scanf("%s", ps->data[ps->size].addr);

    ps->size++;
    printf("添加成功\n");
}

//打印通讯录的信息
void ShowContact(const struct Contact* ps)
{
    if(ps->size == 0)
    {
        printf("通讯录为空\n");
    }
    else
    {
        int i = 0;
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
        for(i = 0; i < ps->size; i++)
        {
             printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
                    ps->data[i].name,
                    ps->data[i].age,
                    ps->data[i].sex,
                    ps->data[i].tele,
                    ps->data[i].addr);
        }
    }
}

static int FindByName(const struct Contact* ps, char name[MAX_NAME])
{
    int i = 0;
    for(i = 0; i < ps->size; i++)
    {
        if(0 == strcmp(ps->data[i].name, name))
        {
            return i;
        }
    }
    return -1;//找不到的情况
}

//删除指定的联系人
void DelContact(struct Contact* ps)
{
    char name[MAX_NAME];
    printf("请输入要删除人的名字：>");
    scanf("%s",name);
    //1.查找要删除的人在什么位置
    //找到了返回名字所在元素的下标
    //找不到返回-1
    int pos = FindByName(ps, name);

    //2.删除
    if(pos == -1)
    {
        printf("要删除的人不存在\n");
    }
    else
    {
        //删除元素
        for(int j = pos; j < ps->size-1; j++)
        {
            ps->data[j] = ps->data[j + 1];
        }
        ps->size--;
        printf("删除成功\n");
    }
}

//查找指定的人的信息
void SearchContact(const struct Contact* ps)
{
    char name[MAX_NAME];
    printf("请输入要查找人的名字：>");
    scanf("%s",name);
    int pos = FindByName(ps, name);
    if(pos == -1)
    {
        printf("要查找的人不存在\n");
    }
    else
    {
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
        printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
                ps->data[pos].name,
                ps->data[pos].age,
                ps->data[pos].sex,
                ps->data[pos].tele,
                ps->data[pos].addr);
    }
}

//修改指定联系人
void ModifyContact(struct Contact* ps)
{
    char name[MAX_NAME];
    printf("请输入要修改人的名字：>");
    scanf("%s",name);
    int pos = FindByName(ps, name);
    if(pos == -1)
    {
        printf("要修改人的信息不存在\n");
    }
    else
    {
        printf("请输入名字：>");
        scanf("%s", ps->data[pos].name);
        printf("请输入年龄：>");
        scanf("%d", &(ps->data[pos].age));
        printf("请输入性别：>");
        scanf("%s", ps->data[pos].sex);
        printf("请输入电话：>");
        scanf("%s", ps->data[pos].tele);
        printf("请输入地址：>");
        scanf("%s", ps->data[pos].addr);
    }
}

int cmp_stu_by_name(const void* e1, const void* e2)
{
    return strcmp(((struct PeoInfo*)e1)->name,((struct PeoInfo*)e2)->name);
}

//排序通讯录的内容
void SortContact(struct Contact* ps)
{
    qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp_stu_by_name);
    ShowContact(ps);
}

//销毁通讯录，释放空间
void DestroyContact(Contact* ps)
{
    free(ps->data);
    ps->data = NULL;
}

//保存文件
void SaveContact(Contact* ps)
{
    FILE* pfWriter = fopen("contact.txt", "wb");
    if(pfWriter == NULL)
    {
        printf("SaveContact::%s\n", strerror(errno));
        return ;
    }
    //写通讯录中的数据到文件中
    int i = 0;
    for(i = 0; i < ps->size; i++)
    {
        fwrite(&(ps->data[i]), sizeof(PeoInfo), 1, pfWriter);
    }
    printf("保存成功\n");
    //关闭文件
    fclose(pfWriter);
    pfWriter = NULL;
}

