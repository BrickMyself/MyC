#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
//栈的实现  数组或者单链表  单链表  的头插头删 头结点用来当做栈顶
// 因此出栈和入栈也就是在头结点处头删和头插
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