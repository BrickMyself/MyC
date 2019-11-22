#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int LTDataType;
typedef struct ListNode
{    
	LTDataType _data;  
	struct ListNode* _next; //ָ����һ������ָ�� 
	struct ListNode* _prev; //ָ��ǰһ������ָ��
}ListNode;
typedef struct List 
{   
	ListNode* _head;//����ͷָ��
}List;
void ListInit(List* plist);//��ʼ��˫����
void ListDestory(List* plist);//ɾ��˫���� 
void ListPushBack(List* plist, LTDataType x);//β��
void ListPopBack(List* plist);//βɾ
void ListPushFront(List* plist, LTDataType x);//ͷ��
void ListPopFront(List* plist);//ͷɾ
LTDataType ListSize(List* plist);//����Ԫ�ظ���
LTDataType ListFind(List* plist, LTDataType x);//�������ݣ�����λ��
void ListInsert(List* plist,LTDataType pos, LTDataType x,LTDataType size); // ��pos��ǰ����в���
void ListErase(List* plist,LTDataType pos,LTDataType size);// ɾ��posλ�õĽڵ�
void ListPrint(List* plist);//��ӡ��������
ListNode* BuyListNode(LTDataType x);//�����㣬�����ڴ�
