//#include<stdio.h>
/**********************				 �Ƚϵݹ���������ַ�����쳲���������                                            */
#include<stdio.h>
int Fib1(int n)//�ݹ�,�㷨ȱ�ݣ����ֳ�����ظ����㣬�˷�������n=50ʱҪ��10����
{

	if (n>2)
		return Fib1(n - 1) + Fib1(n - 2);
	if (n = 1 || 2)
		return 1;
}
long int Fib2(int n)//������շת���˼·��������죬���Է��֣�ͬ������,�õ��㷨Ч�ʸ���
{
	long int a = 1, b = 1, c = 1;
	while (n > 2)//��С�Լ���С����Ҫ��i//for���Ա���������⣬��Ϊ�й��о�
	{
		c = a + b;//���Ի�ͷȥ�Ż�շת���
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()//TDD���������������ȿ�ܣ��ٱ����
{
	long int ret = 0;
	printf("����������쳲�������������,���س�������\n");
	scanf("%d", &ret);
	//printf("%ld\n", Fib1(ret));
	printf("%llu\n", Fib2(ret));

	return 0;
}