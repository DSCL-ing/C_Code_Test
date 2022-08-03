#include<stdio.h>
#include<stdlib.h>//Sleep(1000)
#include<windows.h>//system("cls")

	char arr1[] = "                        ";
	char arr2[] = "welcome to program world";
int left,right;

int main()
{

	printf("请输入Y/y载入系统\n");
	getchar();

	printf("正在加载，请稍后.\n"); Sleep(1000);	system("cls");
	printf("正在加载，请稍后..\n");	Sleep(1000); system("cls");
	printf("正在加载，请稍后...\n"); Sleep(1000);	system("cls");
	printf("正在加载，请稍后.\n");	Sleep(1000); system("cls");
	printf("正在加载，请稍后..\n");	Sleep(1000); system("cls");
	printf("正在加载，请稍后...\n");	Sleep(1000); system("cls");
	printf("加载成功，正在载入\n");	Sleep(1000); system("cls");

	for (left = 0, right = sizeof(arr1) / sizeof(arr1[0]) - 2; left <= right; left++, right--)
	{


		arr1[left] = arr2[left];
		arr1[right] = arr2[right];
		Sleep(500);
		system("cls");
		puts(arr1);

		//printf("%s\n", arr1);
	}
	//printf("%s\n", arr1);
	return 0;
}