#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


int main()
{
	int i = 0;
	int count = 0;
	for (i = 100; i <= 200; i++)//代码优化，i=a*b;由数学得，a和b至少有一个数字《=开平方i；（a和b!=i）
	{                           //16=2*8=4*4；
		int j = 0;              //而找到一个因数，就不需要再找另一个因数，故只需到sqrt（a/b）；
		for (j = 2; j < i/2; j++) //再优化，有数学得，最小非素数为4，只要i》=4时，f(i)>=sqrt(i)即可，显然i/2满足条件;
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
	printf("素数个数为%d", count);
	return 0;
}