#include<stdio.h>
int main()
{
	int i, j, t, a[11];// = { 0, 25, 7, 3, 9, 11, 36, 14, 1, 6, 2 };
	for (i = 1; i <= 10; i++)
		scanf("%d", &a[i]);
	for (i = 1; i <= 9; i++)
		for (j = i + 1; j <= 10; j++)
			if (a[i] < a[j])
			{
		t = a[i];
		a[i] = a[j];
		a[j] = t;
			}
	for (i = 1; i <= 10; i++)
	{
		printf("%d\t", a[i]);
		if (5 == i)
			printf("\n");
	}
	return 0;
}
