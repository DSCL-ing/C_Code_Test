#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


int main()
{
	int i = 0;
	int count = 0;
	for (i = 100; i <= 200; i++)//�����Ż���i=a*b;����ѧ�ã�a��b������һ�����֡�=��ƽ��i����a��b!=i��
	{                           //16=2*8=4*4��
		int j = 0;              //���ҵ�һ���������Ͳ���Ҫ������һ����������ֻ�赽sqrt��a/b����
		for (j = 2; j < i/2; j++) //���Ż�������ѧ�ã���С������Ϊ4��ֻҪi��=4ʱ��f(i)>=sqrt(i)���ɣ���Ȼi/2��������;
		{
			if (i%j == 0)
			{
				break;
			}

		}
		if (i == j)
		{
			count++; printf("%d\t", i);
		}
	}
	printf("��������Ϊ%d", count);
	return 0;
}