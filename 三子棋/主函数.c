<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS 1
#include"ͷ�ļ�.h"

void menu()
{
	printf("************************************\n");
	printf("��������Ϸ\n1����ʼ��Ϸ\n2���˳���Ϸ\n");
	printf("************************************\n");

}

void game()
{
	int ret = 0;//
	char board[ROW][COL] = { ' ' };//��ά���鴫��Ҫѧϰ
	system("cls");
	//��Ϸ��ʾ
	Display(board, ROW, COL);
	//��ʽ������
	InitBoard(board, ROW, COL);
	while (1)//��Ϸ����
	{
		system("cls");
		//��Ϸ��ʾ
		Display(board, ROW, COL);
		
		PlayerMove(board, ROW, COL);//����ƶ�
		ret=IsWin(board, ROW, COL);	//�ж���Ӯ
		if (ret !='c')
		{
			break;
		}
		ComputerMove(board, ROW, COL);		//�����ƶ�
		ret=IsWin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if ('*' == IsWin(board, ROW, COL))//c��continue��==������*==���Ӯ��
		//d(draw)==ƽ�֣�#��lose��==����䣬����Ӯ
	{
		printf("���ʤ��\n");
		printf("�������ת���˵�");
		getch();
	}
	else if ('#' == IsWin(board, ROW, COL))
	{
		printf("����ʤ��\n");
		printf("�밴���������");
		getch();
	}
	else if ('d' == IsWin(board, ROW, COL))
	{
		printf("ƽ��");
		printf("�밴���������");
		getch();
	}
}


int main()
{
	srand((unsigned int)time(NULL));

	int input=0;

	do
	{
		system("cls");
		menu();
		scanf("%d", &input);
		//��Ϸ�˵�
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("��Ϸ������");
			exit(0);

		default:printf("�����������������\n");
		}
	} while (input);
	

	//
	return 0;
=======
#define _CRT_SECURE_NO_WARNINGS 1
#include"ͷ�ļ�.h"

void menu()
{
	printf("************************************\n");
	printf("��������Ϸ\n1����ʼ��Ϸ\n2���˳���Ϸ\n");
	printf("************************************\n");

}

void game()
{
	int ret = 0;//
	char board[ROW][COL] = { ' ' };//��ά���鴫��Ҫѧϰ
	system("cls");
	//��Ϸ��ʾ
	Display(board, ROW, COL);
	//��ʽ������
	InitBoard(board, ROW, COL);
	while (1)//��Ϸ����
	{
		system("cls");
		//��Ϸ��ʾ
		Display(board, ROW, COL);
		
		PlayerMove(board, ROW, COL);//����ƶ�
		ret=IsWin(board, ROW, COL);	//�ж���Ӯ
		if (ret !='c')
		{
			break;
		}
		ComputerMove(board, ROW, COL);		//�����ƶ�
		ret=IsWin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if ('*' == IsWin(board, ROW, COL))//c��continue��==������*==���Ӯ��
		//d(draw)==ƽ�֣�#��lose��==����䣬����Ӯ
	{
		printf("���ʤ��\n");
		printf("�������ת���˵�");
		getch();
	}
	else if ('#' == IsWin(board, ROW, COL))
	{
		printf("����ʤ��\n");
		printf("�밴���������");
		getch();
	}
	else if ('d' == IsWin(board, ROW, COL))
	{
		printf("ƽ��");
		printf("�밴���������");
		getch();
	}
}


int main()
{
	srand((unsigned int)time(NULL));

	int input=0;

	do
	{
		system("cls");
		menu();
		scanf("%d", &input);
		//��Ϸ�˵�
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("��Ϸ������");
			exit(0);

		default:printf("�����������������\n");
		}
	} while (input);
	

	//
	return 0;
>>>>>>> d70a8d97c334de25aeb7937b9967b8d54c155c16
}