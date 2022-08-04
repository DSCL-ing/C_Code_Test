/*******************登录系统****************************/
#include<stdio.h>
int main()
{
	int password[20] = { 0 };
	scanf("%s", password);
	if (strcmp(password, "123456") == 0)//不能直接比较字符串，“字符串不是C语言的基本类型,不能直接比较”
		//必须使用strcmp
	{
		printf("登陆成功\n");
	}
	else
	{
		printf("密码错误，登陆失败\n");
	}
	return 0;
}

