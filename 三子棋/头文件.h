#include<stdio.h>

#include <stdlib.h>
#include<time.h>
//�������ܺ�Ԥ����ָ����ͬ
#define ROW 3   //������дROW������������Сдrow
#define COL 3   //������дCOL������������Сдcol


void Display(char board[ROW][COL], int row, int col);

char IsWin(char board[ROW][COL], int row, int col);

void InitBoard(char board[ROW][COL], int row, int col);

char PlayerMove(char board[ROW][COL], int row, int col);

char ComputerMove(char board[ROW][COL], int row, int col);

char IsFull(char board[ROW][COL], int row, int col);