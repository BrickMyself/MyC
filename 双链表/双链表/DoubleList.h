#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int LTDataType;
typedef struct ListNode
{    
	LTDataType _data;  
	struct ListNode* _next; //指向下一个结点的指针 
	struct ListNode* _prev; //指向前一个结点的指针
}ListNode;
typedef struct List 
{   
	ListNode* _head;//定义头指针
}List;
void ListInit(List* plist);//初始化双链表
void ListDestory(List* plist);//删除双链表 
void ListPushBack(List* plist, LTDataType x);//尾插
void ListPopBack(List* plist);//尾删
void ListPushFront(List* plist, LTDataType x);//头插
void ListPopFront(List* plist);//头删
LTDataType ListSize(List* plist);//链表元素个数
LTDataType ListFind(List* plist, LTDataType x);//查找数据，返回位置
void ListInsert(List* plist,LTDataType pos, LTDataType x,LTDataType size); // 在pos的前面进行插入
void ListErase(List* plist,LTDataType pos,LTDataType size);// 删除pos位置的节点
void ListPrint(List* plist);//打印链表数据
ListNode* BuyListNode(LTDataType x);//创造结点，申请内存
