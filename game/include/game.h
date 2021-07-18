#ifndef GAME_H
#define GAME_H
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10//雷的数目
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void InitBoard(char board[ROWS][COLS], int rows, int cols, char sets);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col);
int get_mine_count(char board[ROWS][COLS], int x, int y);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
#endif // GAME_H
