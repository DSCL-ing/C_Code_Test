#include<stdio.h>
#include<stdlib.h>//Sleep(1000)
#include<windows.h>//system("cls")

	char arr1[] = "                        ";
	char arr2[] = "welcome to program world";
int left,right;

int main()
{

	printf("������Y/y����ϵͳ\n");
	getchar();

	printf("���ڼ��أ����Ժ�.\n"); Sleep(1000);	system("cls");
	printf("���ڼ��أ����Ժ�..\n");	Sleep(1000); system("cls");
	printf("���ڼ��أ����Ժ�...\n"); Sleep(1000);	system("cls");
	printf("���ڼ��أ����Ժ�.\n");	Sleep(1000); system("cls");
	printf("���ڼ��أ����Ժ�..\n");	Sleep(1000); system("cls");
	printf("���ڼ��أ����Ժ�...\n");	Sleep(1000); system("cls");
	printf("���سɹ�����������\n");	Sleep(1000); system("cls");

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