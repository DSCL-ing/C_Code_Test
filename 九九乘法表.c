#include<stdio.h>
/**********************            九九乘法表上三角                                            */
int main()
{                                           //制表符妙用：自动填充空格，自动对齐；
	int i = 0, j = 0, y = 0;                  //其他情况，用%-n,md填充空格
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

/**********************            九九乘法表下三角                                            */
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