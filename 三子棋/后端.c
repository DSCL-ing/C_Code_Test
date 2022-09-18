<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
#include"ͷ�ļ�.h"



void Display(char board[ROW][COL], int row, int col)
{
	printf("���������磨1��2�������س�������\n\n\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
			if (j == col - 1 && i < row - 1)//�ҵķ����ǵ�j���ʺ��ٴ�ӡ�ᣬ�ɶ��ԲЧ�ʵ�
				//��ʦ�ķ�������i������
			{
				printf("\n");
				for (int j = 0; j < col; j++)
				{
					printf("---");
					if (j < col - 1)
					{
						printf("|");
					}
				}
			}
		}
		//printf("\n");
		//if (i < row - 1)//��ʦ����
		//{
		//	for (j = 0; j < col; j++)
		//	{
		//		printf("---");
		//		if (j < col - 1)
		//			printf("|");
		//	}
		//}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	printf("\n");
}

char IsFull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 'c';
		}
	}
	return 'd';
}

char IsWin(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
		if (board[1][1] == board[2][2] && board[2][2] == board[0][0] && board[1][1] != ' ')
			return board[1][1];
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
			return board[1][0];
	}
	int ret = IsFull(board, row, col);
	if ('d'==ret)
	{
		return 'd';
	}
	else
	{
		return 'c';
	}
}

void InitBoard(char board[ROW][COL], int row, int col)
{
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				board[i][j] = ' ';
			}
		}
	}
}



char PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y = 1;
	printf("�����\n");
	while (1)
	{
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <=row&&y >= 1 && y <=col)
			//������>=.intת����Ϊ������������Ӱ��
		{
			if (board[x - 1][y - 1] == ' ') // != '*'&&board[x][y] != '#'
			{
				board[x-1][y-1] = '*';
				system("cls");
				Display(board, ROW, COL);
				break;
			}
			else
			{
				printf("������ռ�ã�����������\n");
			}
		}
		else
		{
			system("cls");
			Display(board, ROW, COL);
			printf("������������������\n");
		}

	}


}

char ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("������\n");
	int x, y = 1;
	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (board[x ][y ] == ' ') //!= '*'&&board[x][y] != '#'
		{
			board[x][y] = '#';
			system("cls");
			Display(board, ROW, COL);
			break;
		}
	}

=======
#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
#include"ͷ�ļ�.h"



void Display(char board[ROW][COL], int row, int col)
{
	printf("���������磨1��2�������س�������\n\n\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
			if (j == col - 1 && i < row - 1)//�ҵķ����ǵ�j���ʺ��ٴ�ӡ�ᣬ�ɶ��ԲЧ�ʵ�
				//��ʦ�ķ�������i������
			{
				printf("\n");
				for (int j = 0; j < col; j++)
				{
					printf("---");
					if (j < col - 1)
					{
						printf("|");
					}
				}
			}
		}
		//printf("\n");
		//if (i < row - 1)//��ʦ����
		//{
		//	for (j = 0; j < col; j++)
		//	{
		//		printf("---");
		//		if (j < col - 1)
		//			printf("|");
		//	}
		//}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	printf("\n");
}

char IsFull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 'c';
		}
	}
	return 'd';
}

char IsWin(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
		if (board[1][1] == board[2][2] && board[2][2] == board[0][0] && board[1][1] != ' ')
			return board[1][1];
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
			return board[1][0];
	}
	int ret = IsFull(board, row, col);
	if ('d'==ret)
	{
		return 'd';
	}
	else
	{
		return 'c';
	}
}

void InitBoard(char board[ROW][COL], int row, int col)
{
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				board[i][j] = ' ';
			}
		}
	}
}



char PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y = 1;
	printf("�����\n");
	while (1)
	{
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <=row&&y >= 1 && y <=col)
			//������>=.intת����Ϊ������������Ӱ��
		{
			if (board[x - 1][y - 1] == ' ') // != '*'&&board[x][y] != '#'
			{
				board[x-1][y-1] = '*';
				system("cls");
				Display(board, ROW, COL);
				break;
			}
			else
			{
				printf("������ռ�ã�����������\n");
			}
		}
		else
		{
			system("cls");
			Display(board, ROW, COL);
			printf("������������������\n");
		}

	}


}

char ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("������\n");
	int x, y = 1;
	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (board[x ][y ] == ' ') //!= '*'&&board[x][y] != '#'
		{
			board[x][y] = '#';
			system("cls");
			Display(board, ROW, COL);
			break;
		}
	}

>>>>>>> d70a8d97c334de25aeb7937b9967b8d54c155c16
}