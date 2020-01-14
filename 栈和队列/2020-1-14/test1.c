#include"queue.h"
void TestQueue()
{
	Queue q;
	QueuePush(&q,1);
	//QueuePush(&q,2);
	//QueuePush(&q,3);
	//QueuePush(&q,4);
	while(QueueEmpty)
	{
		printf("%d ",QueueFront(&q));
		QueuePop(&q);
	}
}
int main()
{
	TestQueue();
	system("pause");
	return 0;
}

