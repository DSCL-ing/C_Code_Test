#include<stdio.h>



int main()
{
	int i, word=0,space =1;
	char a[] = "i am a boy";
	printf("%s\n", a);
	for (i = 0; (a[i]) != '\0'; i++)
	{
		if (a[i] == ' ')
			space = 1;
		else if (space == 1)
		{
			word++;
			space = 0;
		}
		else
			space = 0;
	}
	printf("%d", word);
	return 0;
}
