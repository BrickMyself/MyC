#pragma once
#include<stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
typedef int SDataType;//类型重定义
typedef  struct  SListNode//定义单链表节点结构体
{
	SDataType  _data;//存放节点的数据
	struct SListNode* _next;//存放下一个节点的指针，指向下一个结构体 因此是struct SListNode*类型
}SListNode;
typedef struct Slist//定义单链表
{
	SListNode* head;//定义指向单链表的头指针
}Slist;
void InitSlist(Slist* plt);//初始化单链表
void SLTPushBack (Slist*plt, SDataType value);//尾插
void SLTPushFront (Slist*plt, SDataType value);//头插
void SLTPopBack(Slist* plt);//尾删
void SLTPopFront(Slist* plt);//头删
SDataType   SLTFind(Slist* plt, SDataType x);//查找节点
void SListInsertAfter(Slist*plt,SDataType pos, SDataType x);//在给定位置之后插入一个新节点
void SListEraseAfter(Slist*plt,SDataType pos);//删除指定位置之后的节点
void SListPrintf(Slist*plt);//打印数据
void SListEraseAfterAll(Slist*plt,SDataType pos);//删除指定位之后的所有节点
