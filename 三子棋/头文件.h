<<<<<<< HEAD
#include<stdio.h>

#include <stdlib.h>
#include<time.h>
//参数不能和预处理指令相同
#define ROW 3   //传进大写ROW，参数定义用小写row
#define COL 3   //传进大写COL，参数定义用小写col


void Display(char board[ROW][COL], int row, int col);

char IsWin(char board[ROW][COL], int row, int col);

void InitBoard(char board[ROW][COL], int row, int col);

char PlayerMove(char board[ROW][COL], int row, int col);

char ComputerMove(char board[ROW][COL], int row, int col);

=======
#include<stdio.h>

#include <stdlib.h>
#include<time.h>
//参数不能和预处理指令相同
#define ROW 3   //传进大写ROW，参数定义用小写row
#define COL 3   //传进大写COL，参数定义用小写col


void Display(char board[ROW][COL], int row, int col);

char IsWin(char board[ROW][COL], int row, int col);

void InitBoard(char board[ROW][COL], int row, int col);

char PlayerMove(char board[ROW][COL], int row, int col);

char ComputerMove(char board[ROW][COL], int row, int col);

>>>>>>> d70a8d97c334de25aeb7937b9967b8d54c155c16
char IsFull(char board[ROW][COL], int row, int col);