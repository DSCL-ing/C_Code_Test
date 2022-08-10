#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//四年一闰，百年不润，而四百年又闰
int main()
{
	int year = 0;
	int count = 0;
	for (; year < 4000; year++)
	{
		if ((year % 4 == 0) && (year % 100 != 0))
		{
			count++;
			printf("%d\t", year);
		}
		else if (year % 400 == 0)
		{
			count++;
			printf("%d\t", year);
		}
		//if (((year % 4 == 0)  &&  (year % 100 != 0)) || (year % 400 == 0))
		//{
		//	count++;
		//	printf("%d\t", year);

		//}
		if (count % 5 == 0)
			printf("\n");
	}
	printf("count=%d", count);
	return 0;
}
