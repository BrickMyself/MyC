#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
//ջ��ʵ��  ������ߵ�����  ������  ��ͷ��ͷɾ ͷ�����������ջ��
// ��˳�ջ����ջҲ������ͷ��㴦ͷɾ��ͷ��
typedef int StackDataType;
typedef struct Stack{
	StackDataType* arry;
	size_t _top;
	size_t _capacity;
}Stack;
void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps,StackDataType x);
void StackPop(Stack* ps);
StackDataType StackTop(Stack* ps);
size_t StackSize(Stack*ps);
//bool StackEmpty(Stack*ps);