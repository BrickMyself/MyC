#include<stdio.h>
#include<stdlib.h>
int Fibonacci_1(size_t n)//ע�ⷵ��ֵ���ܻ�ܴ�,��c�������������Ϊ4294967295
{
	int  first,second,third;
	int i;
	first=0;
	second=1;
	if(n<=2)
	{
		return 1;
	}
	for(i=2; i<=n; i++)
	{
		third=first+second;
		first=second;
		second=third;
	}
	return third;
}
int Fibonacci_2(size_t n)
{
	if(n<=2)
	{
		return 1;
	}
	else
		return Fibonacci_1(n-1)+Fibonacci_1(n-2);
}
int main()
{
	size_t n=40;
	printf("�ǵݹ��㷨��%d��쳲�������Ϊ>:%d\n",n,Fibonacci_1(n));
	printf("�ݹ��㷨��%d��쳲�������Ϊ>:%d\n",n,Fibonacci_2(n));
	system("pause");
	return 0;
}