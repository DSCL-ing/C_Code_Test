/*******************��¼ϵͳ****************************/
#include<stdio.h>
int main()
{
	int password[20] = { 0 };
	scanf("%s", password);
	if (strcmp(password, "123456") == 0)//����ֱ�ӱȽ��ַ��������ַ�������C���ԵĻ�������,����ֱ�ӱȽϡ�
		//����ʹ��strcmp
	{
		printf("��½�ɹ�\n");
	}
	else
	{
		printf("������󣬵�½ʧ��\n");
	}
	return 0;
}

