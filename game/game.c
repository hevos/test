#include "game.h"

//初始化
void InitBoard(char board[ROWS][COLS], int rows, int cols, char sets)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            board[i][j] = sets;
        }
    }
}

//打印
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    //打印列号
    for(int i = 0; i <= col; i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    for(int i = 1; i <= row; i++)
    {
        //打印行号
        printf("%d ",i);
        for(int j = 1; j<= col; j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

//布置雷
void SetMine(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;
    while(count)
    {
        int x = rand() % row+1;//1-9
        int y = rand() % col+1;//1-9
        if(board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
    //因为棋盘内的'0'和'1'为字符，需要将它们转为数字
    //因为'1'-'0'=1，所以只要将字符数字减去字符0就得到对应的数字
    return mine[x-1][y] +
    mine[x-1][y-1] +
    mine[x][y-1] +
    mine[x+1][y-1] +
    mine[x+1][y] +
    mine[x+1][y-1] +
    mine[x][y+1] +
    mine[x-1][y+1] - 8*'0';
}

//扫雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;
    int win = 0;
    //棋盘大小9*9， 9*9-10=71个位置不是雷
    while(win < row*col-EASY_COUNT)
    {
        printf("请输入排查雷的坐标：>");
        scanf("%d%d",&x ,&y);
        if(x >= 1 && x <= row && y >=1 && y <= col)
        {
            //坐标合法
            //1.踩雷
            if(mine[x][y] == '1')
            {
                printf("很遗憾，你被炸死了\n");
                DisplayBoard(mine, row, col);
                break;
            }
            //2.不是雷
            else
            {
                //计算x，y坐标周围有几个雷
                int count = get_mine_count(mine, x, y);
                show[x][y] = count + '0';
                DisplayBoard(show, row, col);
            }
            win++;
        }
        else
        {
            printf("输入非法坐标，请重新输入!\n");
        }
    }
    if(win == row*col - EASY_COUNT)
    {
        printf("恭喜你，排雷成功！\n");
        DisplayBoard(mine, row, col);
    }
}
