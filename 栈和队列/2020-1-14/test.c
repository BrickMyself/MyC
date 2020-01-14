#include"satck.h"
void Test1()
{
	Stack ps;
	size_t i=0;
	StackInit(&ps);
	StackPush(&ps,1);
	StackPush(&ps,2);
	StackPush(&ps,3);
	StackPush(&ps,4);
	while(StackSize(&ps))
	{
		printf("%d ",StackTop(&ps));
		StackPop(&ps);
	}
}
//int main()
//{
//	Test1();
//	system("pause");
//	return 0;
//}