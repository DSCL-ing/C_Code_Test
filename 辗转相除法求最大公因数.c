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
	printf("������Ϊ%d������Ϊ%d\n", a, b);
	y = a%b;
	printf("����Ϊ%d\n",y);
	for (; y != 0;)
	{
		beichu = chushu;
		chushu = y;
		y = beichu%chushu;
		if (y == 0)
			break;
	}
	printf("�������Ϊ%d\n", chushu);
}
//��չ�Ż���շת�����ÿһ���Գ�����ӡ������ֱ������Ϊ0ʱֹͣ��
