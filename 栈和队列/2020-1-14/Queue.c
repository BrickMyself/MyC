#include"queue.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front=NULL;
	pq->_tail=NULL;
}
void QueueDestory(Queue* pq)
{
	QueueNode*cur=pq->_front;
	assert(pq);
	while(cur)
	{
		QueueNode* next=cur->_next;
		free(cur);
		cur=next;
	}
	pq->_front=pq->_tail=NULL;
}
QueueNode* BuyQueueNode(QueueDataType x)
{
	QueueNode *node=(QueueNode*)malloc(sizeof(QueueNode));
	node->_data=x;
	node->_next=NULL;
	return node;
}
void QueuePush(Queue* pq, QueueDataType x)
{
	QueueNode* newnode=BuyQueueNode(x);
	if(pq->_tail==NULL)
	{
		pq->_front=pq->_tail=newnode;
	}
	else
	{
		pq->_tail->_next=newnode;
		pq->_tail=newnode;
	}
}
void QueuePop(Queue* pq)
{
	QueueNode* next=pq->_front->_next;
	assert(pq&&pq->_front!=NULL);
	free(pq->_front);
	pq->_front=next;
	if(pq->_front==NULL)
	{
		pq->_tail=NULL;
	}

}
QueueDataType QueueFront(Queue* pq)
{
	assert(pq&&pq->_front!=NULL);
	return pq->_front->_data;
}
QueueDataType QueueBack(Queue* pq)
{
	assert(pq&&pq->_tail!=NULL);
	return pq->_tail->_data;
}
int QueueEmpty(Queue* pq)
{
	if(pq->_front==NULL)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
int QueueSize(Queue* pq)
{
	int size=0;
	QueueNode* cur = pq->_front;
	while(cur)
	{
		++size;
		cur=cur->_next;
	}
	return size;
}
