//#include<stdio.h>
/**********************				 比较递归与迭代两种方法求斐波那契数列                                            */
#include<stdio.h>
int Fib1(int n)//递归,算法缺陷，出现超多次重复计算，浪费算力，n=50时要算10分钟
{

	if (n>2)
		return Fib1(n - 1) + Fib1(n - 2);
	if (n = 1 || 2)
		return 1;
}
long int Fib2(int n)//迭代，辗转相除思路，计算更快，可以发现，同样问题,好的算法效率更高
{
	long int a = 1, b = 1, c = 1;
	while (n > 2)//大到小自减，小到大要引i//for可以避免此类问题，较为中规中矩
	{
		c = a + b;//可以回头去优化辗转相除
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()//TDD测试驱动开发，先框架，再编代码
{
	long int ret = 0;
	printf("请输入所求斐波那契数的项数,按回车键结束\n");
	scanf("%d", &ret);
	//printf("%ld\n", Fib1(ret));
	printf("%llu\n", Fib2(ret));

	return 0;
}