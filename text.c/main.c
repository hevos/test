#include <stdio.h>
#include <string.h>

/*
杨氏矩阵
有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，
请编写程序，在这样的矩阵中查找某个数字是否存在。
要求：时间复杂度小于O(N)
*/

//1 2 3
//4 5 6
//7 8 9

//1 2 3
//2 3 4
//3 4 5

//从右上角的数字找，如果要找的数比右上角的大，删除右上角所在的一行，如果比右上角的小，删除其所在的一列
//左下角同理，但不可在左上角和右下角来找

int FindNum(int arr[3][3], int k, int* px, int* py)
{
    int x = 0;
    int y = *py - 1;
    while(x<=*px-1 && y>=0)
    {
        if(arr[x][y] > k)
        {
            y--;
        }
        else if(arr[x][y] < k)
        {
            x++;
        }
        else
        {
            *px = x;
            *py = y;
            return 1;
        }
    }
    //找不到
    return 0;
}

int main()
{
    int arr[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    int k = 7;
    int x = 3;
    int y = 3;
    //返回型参数
    int ret = FindNum(arr, k, &x, &y);
    if(ret == 1)
    {
        printf("下标是%d %d\n", x, y);
        printf("找到了\n");
    }
    else
    {
        printf("找不到\n");
    }
    return 0;
}
