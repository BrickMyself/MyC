#pragma once
#include<stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
typedef int SDataType;//�����ض���
typedef  struct  SListNode//���嵥����ڵ�ṹ��
{
	SDataType  _data;//��Žڵ������
	struct SListNode* _next;//�����һ���ڵ��ָ�룬ָ����һ���ṹ�� �����struct SListNode*����
}SListNode;
typedef struct Slist//���嵥����
{
	SListNode* head;//����ָ�������ͷָ��
}Slist;
void InitSlist(Slist* plt);//��ʼ��������
void SLTPushBack (Slist*plt, SDataType value);//β��
void SLTPushFront (Slist*plt, SDataType value);//ͷ��
void SLTPopBack(Slist* plt);//βɾ
void SLTPopFront(Slist* plt);//ͷɾ
SDataType   SLTFind(Slist* plt, SDataType x);//���ҽڵ�
void SListInsertAfter(Slist*plt,SDataType pos, SDataType x);//�ڸ���λ��֮�����һ���½ڵ�
void SListEraseAfter(Slist*plt,SDataType pos);//ɾ��ָ��λ��֮��Ľڵ�
void SListPrintf(Slist*plt);//��ӡ����
void SListEraseAfterAll(Slist*plt,SDataType pos);//ɾ��ָ��λ֮������нڵ�
