#include<stdio.h>
/**********************            �žų˷���������                                            */
int main()
{                                           //�Ʊ�����ã��Զ����ո��Զ����룻
	int i = 0, j = 0, y = 0;                  //�����������%-n,md���ո�
	for (i = 1; i <= 9; i++)
		for (j = i; j <= 9;j++)
	{
		y = i*j;
		printf("%d*%d=%d\t", i, j, y);
		if (j == 9)
			printf("\n");
	}
	return 0;
}

/**********************            �žų˷���������                                            */
int main()
{
	int i = 0, j = 0, y = 0;
	for (i=1;i<=9;i++)
		for (j=1;j<=i;j++)
	{
		y = i*j;
		printf("%d*%d=%d\t", i, j, y);
		if (i == j)
		printf("\n");
	}
	return 0;
}