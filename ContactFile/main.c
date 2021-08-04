#include "ContactFile.h"

//ʵ�ֺ����Ĺ���
//�Ľ��汾����̬�����İ汾��ǰ�������Ӵ洢

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
    //����ͨѶ¼
    struct Contact con;//con����ͨѶ¼����߰�����1000��Ԫ�ص�����size
    //��ʼ��ͨѶ¼
    InitContact(&con);
    do
    {
        menu();
        printf("��ѡ��>");
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
            //����ͨѶ¼ - �ͷŶ�̬���ٵ��ڴ�
            SaveContact(&con);
            DestroyContact(&con);
            printf("�˳�ͨѶ¼\n");
            break;
        default:
            printf("ѡ�����\n");
            break;
        }
    }while(input);
    return 0;
}