#include "ContactFile.h"

//实现函数的功能
//改进版本：动态增长的版本的前提下增加存储

void menu()
{
    printf("*******************************\n");
    printf("***1.add       2.del   ********\n");
    printf("***3.search    4.modify********\n");
    printf("***5.show      6.sort  ********\n");
    printf("***7.save      0.exi   ********\n");
    printf("*******************************\n");
}

int main()
{
    int input = 0;
    //创建通讯录
    struct Contact con;//con就是通讯录，里边包含：1000个元素的数和size
    //初始化通讯录
    InitContact(&con);
    do
    {
        menu();
        printf("请选择：>");
        scanf("%d", &input);
        switch(input)
        {
        case ADD:
            AddContact(&con);
            break;
        case DEL:
            DelContact(&con);
            break;
        case SEARCH:
            SearchContact(&con);
            break;
        case MODIFY:
            ModifyContact(&con);
            break;
        case SHOW:
            ShowContact(&con);
            break;
        case SORT:
            SortContact(&con);
            break;
        case SAVE:
            SaveContact(&con);
            break;
        case EXIT:
            //销毁通讯录 - 释放动态开辟的内存
            SaveContact(&con);
            DestroyContact(&con);
            printf("退出通讯录\n");
            break;
        default:
            printf("选择错误\n");
            break;
        }
    }while(input);
    return 0;
}
