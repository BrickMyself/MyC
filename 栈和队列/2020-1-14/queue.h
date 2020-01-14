#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
typedef int QueueDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QueueDataType _data;
}QueueNode;
typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _tail;
}Queue;
void QueueInit(Queue* pq); 
void QueueDestory(Queue* pq);
QueueNode* BuyQueueNode(QueueDataType x); 
void QueuePush(Queue* pq, QueueDataType x);
void QueuePop(Queue* pq);
QueueDataType QueueFront(Queue* pq);
QueueDataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);