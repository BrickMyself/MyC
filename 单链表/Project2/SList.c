#include"SList.h"
Slist lt;//����һ��Slist �ı��� lt;

void InitSlist(Slist* plt)//��ʼ��������
{
	assert(plt);
	plt->head=NULL;
	if(plt->head==NULL)
	{
	printf("��ʼ���ɹ���\n");
	}
	else
	{
		printf("��ʼ��ʧ�ܣ�");
	}

}
void SLTPushBack (Slist*plt, SDataType value)//β��
{      //β��Ļ���˼���ǣ��Ȱ����ݴ�ŵ��½ڵ�������򲢰�next�ÿ�
	//Ȼ���ҵ�β�ڵ���뼴��
	
	SListNode* newnode=(SListNode*)malloc(sizeof(SListNode));//Ϊ�½�㿪�ٿռ�
	SListNode*cur=plt->head;
	newnode->_data=value;
	newnode->_next=NULL;
	if(plt->head==NULL)//�������Ϊ�գ�ֱ�ӽ�ͷָ��ָ���½��
	{
		plt->head=newnode;
	}
	else//�ҵ��������β
	{
		while(cur->_next!=NULL)
		{
			cur=cur->_next;
		}
		cur->_next=newnode;//
	}
}
void SLTPushFront (Slist*plt, SDataType value)//ͷ��
{    //��β������һ��
	//��������Ҫ���ǲ����˳���Ƚ�Ҫ������½���ԭ����ͷ������ϣ�
	//�ٺ�ͷָ������
	
    SListNode*newnode=(SListNode*)malloc(sizeof(SListNode));
	assert(plt);
	newnode->_data=value;
	newnode->_next=NULL;
	newnode->_next=plt->head;
	plt->head=newnode;
}
void SLTPopBack(Slist* plt)//βɾ
{
	//����Ҫ�ҵ�βȻ�����ɾ�������������м�����������
	SListNode* cur=plt->head;
	assert(plt);
	if(cur==NULL)//�������Ϊ��
	{
		return;
	}
	else if((cur->_next)==NULL)//ֻ��һ������
	{
		free(cur);
		plt->head=NULL;
	}
	else {
		while((cur->_next->_next)!=NULL)//��������ҵ�β����ǰһ��
		{      
			cur=cur->_next;
		}
		//��ǰһ������next �ͷŵ���Ȼ�����ÿ�
		//����ֱ���ͷ����һ�����µ����ڶ�����next���Ҳ�����һ�����Ҳ��Ϊ��
		//������ͷŵ����ڶ�����next,�������ڶ�����next�ÿ�
		free(cur->_next);
		cur->_next=NULL;
	}
}
void SLTPopFront(Slist* plt)//ͷɾ
{
	//ͷɾҲ���ǰ�ͷָ��͵�һ������next�������������ͷŵ���һ�����
	//��Ҫע����������������ͷŷ����Ҳ�����һ������next
	assert(plt);
	if(plt->head==NULL)
	{
		return ;
	}
	else
	{
	SListNode*cur=plt->head;
	plt->head=cur->_next;
	free(cur);
	cur=NULL;
	}
}
SDataType   SLTFind(Slist* plt, SDataType x)//�������ݷ���λ��
 {   
	 int count=1;//����һ������������λ�õķ���ֵ
	 SListNode*cur=plt->head;
	 assert(plt&&x);
	 
	 if(plt->head==NULL)
	 {
		 return -1;
	 }
	 if(cur->_data==x&&cur->_next!=NULL)
	 {
		 return 1;//�����һ�����Ƿ���λ��1
	 }
	 else
	 {	 
		 while(cur->_next!=NULL)
		 { 
			 if(cur->_data!=x)//����ȼ�������++�����Ҽ�������߱���һ��
			 {
				count++;	
				cur=cur->_next;
			 } 
	     }
		  if(cur->_data==x)
		    {
		  	    return count;//�ҵ��ͷ���λ��
		    }
		   else
				 return -1;//��û���ҵ�����-1
     }
}


void SListInsertAfter(Slist*plt,SDataType pos, SDataType x)//�ڸ���λ��֮�����һ���½ڵ�
{
	SDataType count=1;
	SListNode*cur=plt->head;
	SListNode*newnode=(SListNode*)malloc(sizeof(SListNode));
	newnode->_data=x;
	newnode->_next=NULL;
	while(count!=pos&&cur->_next!=NULL)//�ҵ�posλ�õĽ��
	{
		count++;
		cur=cur->_next;
	}
	if(count==pos)//�ҵ�ʱ����
	{
	  newnode->_next=cur->_next;//�Ƚ��½���next����ǰ�����next
	  cur->_next=newnode;
	}


}
void SListEraseAfter(Slist*plt,SDataType pos)//��ɾ��ָ��λ�õĽڵ�
{
	SDataType count=1;
	SListNode*cur1=plt->head;
	if(pos==1)
	{
    SListNode*cur=plt->head;
	plt->head=cur->_next;
	free(cur);
	cur=NULL;
	}
	while(count!=pos&&cur1->_next!=NULL)//�ҵ�posλ�õĽ��
	{
		count++;
		cur1=cur1->_next;
	}
	if((pos)==count&&pos!=1)
	{
		SListNode*Next=cur1->_next->_next;
		free(cur1->_next);
		cur1->_next=NULL;
		cur1->_next=Next;

	}


}
void SListEraseAfterAll(Slist*plt,SDataType pos)//��ɾ��ָ��λ�õĽڵ�
{
	SDataType count=1;
	SListNode*cur=plt->head;
	assert(plt);
	if(pos==1)
	{
		free(cur->_next);
		cur->_next=NULL;
	}
	while(count!=pos&&cur->_next!=NULL)//�ҵ�posλ�õĽ��
	{
		count++;
		cur=cur->_next;
	}
	if((pos)==count&&pos!=1)
	{
		free(cur->_next);
		cur->_next=NULL;
	}

}

void SListPrintf(Slist*plt)//��ӡ����
{
	SListNode*cur=plt->head;
    assert(plt);
	while(cur!=NULL)
	{
		printf("%d ",cur->_data);
		cur=cur->_next;
	}
	printf("\n");
}
