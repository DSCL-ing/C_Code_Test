#include<stdio.h>
#include<math.h>
	int k1 = 24, k2 = 38;
	int a = 0;
	int b = 0;
		int y=0; 
		int beichu=0,chushu = 0;
		
int main()
{
if(k1>k2)
{
a=k1;
b=k2;
}
else
{
	a=k2;
	b=k1;
}
beichu=a;
  chushu=b;
	printf("被除数为%d，除数为%d\n", a, b);
	y = a%b;
	printf("余数为%d\n",y);
	for (; y != 0;)
	{
		beichu = chushu;
		chushu = y;
		y = beichu%chushu;
		if (y == 0)
			break;
	}
	printf("最大公因数为%d\n", chushu);
}
//拓展优化：辗转相除的每一步试除都打印出来，直到余数为0时停止。
