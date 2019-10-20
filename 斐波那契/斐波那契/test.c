#include<stdio.h>
#include<stdlib.h>
int Fibonacci_1(size_t n)//注意返回值可能会很大,但c语言中最大整数为4294967295
{                        //测试后只能计算前46个斐波那契额数列
	int  first,second,third;//非递归算法
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
int Fibonacci_2(size_t n)//递归算法
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
	size_t n=45;
	printf("非递归算法第%d个斐波那契数为>:%d\n",n,Fibonacci_1(n));
	printf("递归算法第%d个斐波那契数为>:%d\n",n,Fibonacci_2(n));
	system("pause");
	return 0;
}
