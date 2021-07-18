#include <stdio.h>
#include <stdlib.h>
#include "game.h"

/*
扫雷游戏
需要两个棋盘，一个是布置的棋盘，一个是玩家玩的棋盘
输入扫雷坐标后，如果没有爆炸，需要排查，输出周围雷的数目，
所以可能会下标越界，需要扩大棋盘（从9*9到11*11）
*/

void menu()
{
    printf("*****************************\n");
    printf("*****1.play*****0.exit*******\n");
    printf("*****************************\n");
}

void game()
{
    //雷的信息存储
    //1.布置好的雷的信息
    char mine[ROWS][COLS] = {0};//11*11
    //2.排查好的类的信息
    char show[ROWS][COLS] = {0};
    //初始化
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    //打印棋盘
    //DisplayBoard(mine, ROW, COL);
    DisplayBoard(show, ROW, COL);
    //布置雷
    SetMine(mine, ROW, COL);
    //DisplayBoard(mine, ROW, COL);
    //扫雷
    FindMine(mine, show, ROW, COL);
}

void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择：>");
        scanf("%d",&input);
        switch(input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏！\n");
            break;
        default:
            printf("选择错误，请重新选择");
            break;
        }
    }while(input);
}
int main()
{
    test();
    return 0;
}
